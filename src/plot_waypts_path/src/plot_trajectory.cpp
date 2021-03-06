
/**
\file   plot2d_waypts_path.cpp
\brief  plot path between waypoint for 2 joints
 *
 *  this node subsscribe to the topic contains the states of the joints "topic_name",and to the cmd_pos/cmd_vel topic,
 *  then it plots the trajectories that are received through the cmd_topic and and topic_name
 * run this node by passing the topic_name of the topic that contains the state of 6 joint and mode for commanded pos/vel
 * $ rosrun plot_trajectory plot2d_trajectory _topic_name:= topic_name _mode:= "pos" or "vel"
 *  topic_name= "/state_last_waypts" or "/state_each_waypts" for the two cases we have
\author  Mahmoud Ali
\date    3/5/2019
*/


#include<vector>
#include<iostream>
#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"
//#include "custom_msgs/state_msg.h"

#include <python2.7/Python.h>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


int n_jts=6;  // default number of joint is 6, can be changed by passing n_jts as param while running the node
bool cmd_pos_received= false;
std::vector<std::vector<double>> cmd_pos, state;

// cmd_pos callback
void cmd_call_back(std_msgs::Float64MultiArray msg){
    cmd_pos_received = true;
    for(int i=0; i<n_jts; i++)
        cmd_pos[i].push_back(msg.data[i]);
}


// state callback
void state_call_back(std_msgs::Float64MultiArray msg){
//    cmd_pos_received = true;
        for(int i=0; i<4*n_jts + 6; i++) // 4 for each joint(pos, vel, acc, jrk) + 4 represent commanded waypoint
            state[i].push_back(msg.data[i]);
        for(int i=0; i<n_jts; i++){
            if(cmd_pos_received)
               cmd_pos[i].push_back(cmd_pos[i].back()); // to compare difference bet. cmd_pos and surrent_state
            }
//        ROS_INFO_STREAM("joint_0: pos=" << msg.data[0] <<",  vel= " << msg.data[1]);
}




int main(int argc, char **argv)
{
    ros::init(argc, argv, "plot2d_trajectory");
    ros::NodeHandle nh;
    ros::NodeHandle nh_("~");
    ROS_INFO(" test plot2d_trajectory ...  ");
    std::string topic_name, mode="pos";
    nh_.getParam("topic_name", topic_name);
    nh_.getParam("n_jts", n_jts);
    nh_.getParam("topic_name", topic_name);
    nh_.getParam("mode", mode);
    ROS_INFO("subscribe to  %s , #joints= %d , #mode= %s ", topic_name.c_str(), n_jts, mode.c_str());

    ros::Subscriber cmd_pos_sub =nh.subscribe<std_msgs::Float64MultiArray>("/cmd_pos", 100, cmd_call_back);
    ros::Subscriber state_sub =nh.subscribe<std_msgs::Float64MultiArray>(topic_name, 100, state_call_back);
    // initial the cmd_pos and outpos vector for number of joint
    cmd_pos.resize(n_jts);
    state.resize( 4*n_jts + 6);

    while(ros::ok()){
       ros::spinOnce(); //store the state at each sample time
//       if(!cmd_pos_received)
//       for (int jt=0; jt< n_jts; jt++)
//           ROS_INFO_STREAM("pos: "<< cmd_pos[jt][0]);

    }

        //plot all state
        std::string jt_name;
        std::vector< std::string> sbplt_name ={"position", "velocity", "acceleration", "jerk"};//subplots title
        std::vector< std::string> clr={"b", "k", "r", "g", "m", "c" }; //so joints colors are same for different subplots




        // Plot1: all states , all joints in one_fig using subplot
        for (int sbplt=0; sbplt< 4; sbplt++) {
            for (int jt=0; jt< n_jts; jt++) {
                jt_name= "jt_" + std::to_string(jt);
                plt::subplot(2,2,sbplt+1);
                plt::named_plot(jt_name, state[4*jt+ sbplt], clr[jt]  );
                plt::title(sbplt_name[sbplt]); // Add graph title
                plt::legend(); // Enable legend.
            }
        }
        plt::show();


        // Plot2: each states in seperate fig
        for (int st=0; st< 4; st++) {
            for (int jt=0; jt< n_jts; jt++) {
                jt_name= "jt_" + std::to_string(jt);

                plt::named_plot(jt_name, state[4*jt+ st], clr[jt] );

                if(st==0 && mode=="pos"){
                    jt_name= "ref_jt_" + std::to_string(jt);
                    plt::plot(cmd_pos[jt] , clr[jt] + "--");
                }
                if(st==1 && mode=="vel"){
                    jt_name= "ref_jt_" + std::to_string(jt);
                    plt::plot( cmd_pos[jt] , clr[jt]+ "--");
                }

                plt::title(sbplt_name[st]); // Add graph title
                plt::legend(); // Enable legend.
            }
            plt::show();
        }




        /// Plot3: all states joint in subplots 4x6
        for (int st=0; st< 4; st++) {
            for (int jt=0; jt< n_jts; jt++) {
                jt_name= "jt_" + std::to_string(jt);
                plt::subplot(4,6, 6*st+jt+1);
                plt::named_plot(jt_name, state[4*jt+ st] );

                if(st==0 && mode=="pos"){
                    jt_name= "ref_jt_" + std::to_string(jt);
                    plt::plot( cmd_pos[jt] , "r--"); //reference
                }
                if(st==1 && mode=="vel"){
                    jt_name= "ref_jt_" + std::to_string(jt);
                    plt::plot( cmd_pos[jt] , "r--"); //reference
                }

                plt::title(sbplt_name[st]); // Add graph title
                plt::legend(); // Enable legend.
                if(st==3)
                    plt::ylim(-1200, 1200);
            }

        }
        plt::show();







       // Plot4: each joint in seperate fig
        for (int jt=0; jt< n_jts; jt++) {
            for (int sbplt=0; sbplt< 4; sbplt++) {
                jt_name= "jt_" + std::to_string(jt);
                plt::subplot(2,2,sbplt+1);
                plt::named_plot(jt_name, state[4*jt+ sbplt] ); // pos of joints 5 and joint 6
                if(sbplt==0  && mode=="pos"){
                    jt_name= "ref_jt_" + std::to_string(jt);
                    plt::plot( cmd_pos[jt], "r--" );
                }
                if(sbplt==1 && mode=="vel"){
                    jt_name= "ref_jt_" + std::to_string(jt);
                    plt::plot(cmd_pos[jt] , "r--");
                }

                plt::title(sbplt_name[sbplt]); // Add graph title
                plt::legend(); // Enable legend.
            }
            plt::show();
        }


return 0;


}
