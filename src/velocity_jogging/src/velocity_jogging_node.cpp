/**
\file   velocity_jogging_node.cpp
\brief
 * default frequency: 125.
\author  Mahmoud Ali
\date    16/5/2019
*/



#include "ros/ros.h"
#include "six_dof_vel_controller.h"
#include "ext_work.h"
#include "std_msgs/Float64MultiArray.h"
//#include "queue"
//#include "s_curve_functions.cpp"
const double sm=180,  vm=130,  am=250, jm=1000,  cnt= 1e-2, frq=125;


bool check_vel_limit(std_msgs::Float64MultiArray & vel_msg){
    for (int jt=0; jt< 6; jt++) {
        if(vel_msg.data[jt]>sm )
            vel_msg.data[jt] = sm;
        if(vel_msg.data[jt]< -sm )
            vel_msg.data[jt] = -sm;

    }
}


P_six_dof_vel_controller_T six_dof_vel_controller_P;
ExtU_six_dof_vel_controller_T six_dof_vel_controller_U;
ExtY_six_dof_vel_controller_T six_dof_vel_controller_Y;


std::vector<double>  last_cmd_vel;
bool cmd_vel_received = false;


// command velitions call_back
void cmd_call_back(std_msgs::Float64MultiArray msg){
    cmd_vel_received = true;
     check_vel_limit(msg);
    for(int i=0; i<6; i++){
//        ROS_INFO_STREAM("cmd_vel_received: msg.data[" << i << "] =  " << msg.data[i]);
        last_cmd_vel[i] = msg.data[i];
    }

}



int main(int argc, char **argv)
{

    // initialization of the model and variable
    std::vector<double>  crnt_vel;

    ROS_INFO_STREAM(" start_node: model initializeation  ...... ");
    for(int i=0; i<6; i++){
//       six_dof_vel_controller_U.pos[i] =0;
       six_dof_vel_controller_U.vel[i] =0;
       six_dof_vel_controller_U.acc[i] =0;

       six_dof_vel_controller_Y.POS[i] =0;
       six_dof_vel_controller_Y.VEL[i] =0;
       six_dof_vel_controller_Y.ACC[i] =0;
       six_dof_vel_controller_Y.JRK[i] =0;

       six_dof_vel_controller_P.sm[i] =sm;
       six_dof_vel_controller_P.vm[i] =vm;
       six_dof_vel_controller_P.am[i] =am;
       six_dof_vel_controller_P.jm[i] =jm;

       six_dof_vel_controller_P.kv[i] =20;
       six_dof_vel_controller_P.ka[i] =8;


       last_cmd_vel.push_back(0);
       crnt_vel.push_back(0);
    }
   six_dof_vel_controller_initialize();




  ros::init(argc, argv, "controller_approaching_each_waypoint");
  ros::NodeHandle nh;
  ros::Publisher pub_current_state=nh.advertise<std_msgs::Float64MultiArray>("/out_state", 1000);
  ros::Subscriber sub_cmd_vel = nh.subscribe<std_msgs::Float64MultiArray>("/cmd_vel", 100, cmd_call_back);

  // a message contains the state (vel, vel, acc, jrk) for each joint joint
  std_msgs::Float64MultiArray state_msg;
  ros::Rate loop_rate(frq);

  double stop_dist=sm; //limit
  double dist_vec[6]={sm, sm, sm,  sm, sm, sm};
  int  lmt_stop_idx[6] = {0,0,0, 0,0,0};

  while (ros::ok())
  {
      loop_rate.sleep();
      ros::spinOnce();
      if(!cmd_vel_received) // no waypoints have been recevied
              continue;

      // setting right velocity (cmd_vel or zero if near to the limit)
      for (int jt=0; jt< 6; jt++){
          if(lmt_stop_idx[jt]==0)
              six_dof_vel_controller_U.vel[jt] = last_cmd_vel[jt];
          else if (lmt_stop_idx[jt]==1 && last_cmd_vel[jt]<0)
              six_dof_vel_controller_U.vel[jt] = last_cmd_vel[jt];
          else if (lmt_stop_idx[jt]==-1 && last_cmd_vel[jt]>0)
              six_dof_vel_controller_U.vel[jt] = last_cmd_vel[jt];
          else //reach limit and cmd_vel trying to push it to extreme beyound limit
              six_dof_vel_controller_U.vel[jt] = 0;
      }

    // run the model STEP fumction
    six_dof_vel_controller_step();


    //check pos_limits
     for (int jt=0; jt< 6; jt++){
        stop_dist = .5*1*abs(six_dof_vel_controller_Y.VEL[jt]);
        dist_vec[jt] = stop_dist; //just to print out values
        if(stop_dist >= 180 - abs(six_dof_vel_controller_Y.POS[jt]) ){
            lmt_stop_idx[jt]= six_dof_vel_controller_Y.POS[jt]>0 ? 1:-1;
        }
    }


    // get the output of the model, vel, Vel, Acc, Jrk
    state_msg.data.clear();
    for (int i=0; i<6; i++) {
        state_msg.data.push_back(six_dof_vel_controller_Y.POS[i]);
        state_msg.data.push_back(six_dof_vel_controller_Y.VEL[i]);
        state_msg.data.push_back(six_dof_vel_controller_Y.ACC[i]);
        state_msg.data.push_back(six_dof_vel_controller_Y.JRK[i]);
    }


    // store the input of the controller for further check, setpoint for all the joint: data[24, 25 .... 29]
    for (int i=0; i<6; i++) {
         state_msg.data.push_back(six_dof_vel_controller_U.vel[i]);
         crnt_vel[i] = six_dof_vel_controller_Y.VEL[i];
    }

    //send the state (pos, vel, acc, jrk) for all the joint: 1st_jt=0:3, 2nd_jt=4:7, 3rd_jt:8_11 ..... and so on
    pub_current_state.publish(state_msg);
    ROS_INFO_STREAM("STEP: in_vel= "<< six_dof_vel_controller_U.vel[0] <<"  out_pos= "<< six_dof_vel_controller_Y.POS[0] <<"  out_vel= "<< six_dof_vel_controller_Y.VEL[0] <<"  out_acc= "<< six_dof_vel_controller_Y.ACC[0]);
    ROS_INFO_STREAM("STEP: stop_dist= \n"<< dist_vec[0] << "   " << dist_vec[1] << "   " << dist_vec[2] << "   "<< dist_vec[3] << "   "<<dist_vec[4] << "   "<<dist_vec[5] );


  }

  // terminate model
   six_dof_vel_controller_terminate();
  return 0;
}
// okay first things first:
// 1. reading files for cpp for robotics practical 
// 2. Gijs, update on both ways, try you own way.
// see what do you want if you join, lastest presentation: probably I want to join them as well in room D upstairs lets see what is gooinf on 
// ya rab help me to be accepted in the phd posoion on france nice on event based camera. lfnnhnj omdjkk hfuke kfislmfji 
