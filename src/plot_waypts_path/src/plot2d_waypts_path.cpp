
/**
\file   plot2d_waypts_path.cpp
\brief  plot path between waypoint for 2 joints
 *
 *  this node subsscribe to the topic contains the states of the joints "topic_name",and to the cmd_pos topic,
 *  then it plots the waypoints that are received through the cmd_topic and
 *  the path between them which recevied throught the topic  "topic_name".
 * run this node by passing the topic_name of th etopic that contains the state of 6 joint
 * $ rosrun plot_trajectory plot2d_trajectory _topic_name:= topic_name
 *  topic_name= "/state_last_waypts" or "/state_each_waypts" for the two cases we have
\author  Mahmoud Ali
\date    3/5/2019
*/


#include<vector>
#include<iostream>
#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"

#include <python2.7/Python.h>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


bool cmd_pos_received= false;
std::vector<std::vector<double>> cmd_pos, state;

// cmd_pos callback
void cmd_call_back(std_msgs::Float64MultiArray msg){
    cmd_pos_received = true;
    for(int i=0; i<6; i++)
        cmd_pos[i].push_back(msg.data[i]);
}


// state callback
void state_call_back(std_msgs::Float64MultiArray msg){
    cmd_pos_received = true;
        for(int i=0; i<30; i++)
            state[i].push_back(msg.data[i]);
//        ROS_INFO_STREAM("state_16: " << msg.data[16] <<",  state_20: " << msg.data[16]);
}




int main(int argc, char **argv)
{
    ros::init(argc, argv, "plot2d_trajectory");
    ros::NodeHandle nh;
    ros::NodeHandle nh_("~");
    ROS_INFO(" test plot2d_trajectory ...  ");
    std::string topic_name;
    nh_.getParam("topic_name", topic_name);
    ROS_INFO("subscribe to : %s", topic_name.c_str());

    ros::Subscriber cmd_pos_sub =nh.subscribe<std_msgs::Float64MultiArray>("/cmd_pos", 100, cmd_call_back);
    ros::Subscriber state_sub =nh.subscribe<std_msgs::Float64MultiArray>(topic_name, 100, state_call_back);
    // initial the cmd_pos and outpos vector for number of joint
    cmd_pos.resize(6);
    state.resize(30);

    while(ros::ok()){
       ros::spinOnce();
//       if(!cmd_pos_received)
//           break;

    }

     plt::named_plot("waypoints",cmd_pos[4], cmd_pos[5], "*" ); // commanded position for joint 5, and 6
    plt::named_plot("q1q2_traj",state[16],  state[20] ); // pos of joints 5 and joint 6
//    plt::named_plot("q1&q2", x, z);
    // Set x-axis to interval [0,1000000]
    plt::xlim(0, 2);
    plt::ylim(0, 2);
    plt::xlabel("q1");
    plt::ylabel("q2");
    // Add graph title
    plt::title("2_dof_waypt");
    // Enable legend.
    plt::legend();

    plt::show();

return 0;


}
