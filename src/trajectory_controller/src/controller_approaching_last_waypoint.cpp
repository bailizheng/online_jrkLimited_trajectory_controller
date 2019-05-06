/**
\file   controller_approaching_last_waypoint.cpp
\brief  to generate jerk limited trajectory for the commanded waypoints.
 *
 *  this node subsscribe to the cmd_pos topic, and publish the trajectories to reach this cmd_pos,
 *  it publishes the state ( pos, vel, acc, jrk ) for all the joints through the topic "/state_last_waypts",
 *  the message that contains the state of all the joint is Float64MultiArray msg, each joint has 4 states,
 *  starting from joint_0 with index 0-3 then joint_1 with index 5-7 .. and so on
 *  the trajectory will keep track of th elast point sent through the cmd_pos topic,
 *  so if a new waypoint comes before reaching the current waypoint, 
 *  the controller will neglect the current waypoint and approach the last one.
 *  limits:
 *  sm: position limit, vm:velocity limit, am: acceleration limit, jm:jerk limit.
 *  this controller based on simulink model which is attached in th e include files.
 * default frequency: 125.
\author  Mahmoud Ali
\date    3/5/2019
*/


#include "ros/ros.h"
#include "six_dof_pos_controller.h"
#include "ext_work.h"
#include "std_msgs/Float64MultiArray.h"

const double sm=180,  vm=130,  am=250, jm=1000, frq=125;

P_six_dof_pos_controller_T six_dof_pos_controller_P;
ExtU_six_dof_pos_controller_T six_dof_pos_controller_U;
ExtY_six_dof_pos_controller_T six_dof_pos_controller_Y;


std::vector<double> last_wpt;
bool cmd_pos_received = false;


// command positions call_back
void cmd_call_back(std_msgs::Float64MultiArray msg){
    cmd_pos_received = true;
    for(int i=0; i<6; i++){
        ROS_INFO_STREAM("cmd_tu_received: msg.data[" << i << "] =  " << msg.data[i]);
        last_wpt[i]= msg.data[i];
    }
}



int main(int argc, char **argv)
{


    ROS_INFO_STREAM(" start_node: model initialization  ...... ");

    std::vector<double> crnt_pos;
    for(int i=0; i<6; i++){
       six_dof_pos_controller_U.pos[i] =0;
       six_dof_pos_controller_U.vel[i] =0;
       six_dof_pos_controller_U.acc[i] =0;

       six_dof_pos_controller_Y.POS[i] =0;
       six_dof_pos_controller_Y.VEL[i] =0;
       six_dof_pos_controller_Y.ACC[i] =0;
       six_dof_pos_controller_Y.JRK[i] =0;

       six_dof_pos_controller_P.sm[i] =sm;
       six_dof_pos_controller_P.vm[i] =vm;
       six_dof_pos_controller_P.am[i] =am;
       six_dof_pos_controller_P.jm[i] =jm;

       six_dof_pos_controller_P.kp[i] =1200;
       six_dof_pos_controller_P.kv[i] =400;
       six_dof_pos_controller_P.ka[i] =20;

       last_wpt.push_back(0);
       crnt_pos.push_back(0);
    }

    six_dof_pos_controller_initialize();


    ros::init(argc, argv, "controller_approaching_last_waypoint");
    ros::NodeHandle nh;
    ros::Publisher pub_current_state=nh.advertise<std_msgs::Float64MultiArray>("/state_last_waypts", 1000);
    ros::Subscriber sub_torque = nh.subscribe<std_msgs::Float64MultiArray>("/cmd_pos", 100, cmd_call_back);


    // a message contains the state (pos, vel, acc, jrk) for each joint joint
    std_msgs::Float64MultiArray state_msg;
    ros::Rate loop_rate(frq);
    bool reach_waypt = false;


    while (ros::ok())
        {
        loop_rate.sleep();
        ros::spinOnce();
        if(!cmd_pos_received)// no waypoints have been recevied
            continue;

        // update the model with last waypoint
        for (int jt=0; jt< 6; jt++)
            six_dof_pos_controller_U.pos[jt] = last_wpt[jt];

        //  run the model STEP fumction
        six_dof_pos_controller_step();
        // get the output of the model, Pos, Vel, Acc, Jrk
        state_msg.data.clear();
        for (int i=0; i<6; i++) {
            state_msg.data.push_back(six_dof_pos_controller_Y.POS[i]);
            state_msg.data.push_back(six_dof_pos_controller_Y.VEL[i]);
            state_msg.data.push_back(six_dof_pos_controller_Y.ACC[i]);
            state_msg.data.push_back(six_dof_pos_controller_Y.JRK[i]);
        }

        // store the input of the controller for further check, setpoint for all the joint: data[24, 25 .... 29]
        for (int i=0; i<6; i++) {
            state_msg.data.push_back(six_dof_pos_controller_U.pos[i]);
            crnt_pos[i] = six_dof_pos_controller_Y.POS[i];
        }

        //send the state (pos, vel, acc, jrk) for all the joint: 1st_jt=0:3, 2nd_jt=4:7, 3rd_jt:8_11 ..... and so on
        pub_current_state.publish(state_msg);

        ROS_INFO_STREAM("STEP: inpos= "<< six_dof_pos_controller_U.pos[0] <<"  outpos= "<< six_dof_pos_controller_Y.POS[0] <<"  out_vel= "<< six_dof_pos_controller_Y.VEL[0] <<"  out_acc= "<< six_dof_pos_controller_Y.ACC[0]);

        }

  // terminate model
   six_dof_pos_controller_terminate();
  return 0;
}
