/**
\file   cmd_pos_publisher.cpp
\brief  to publish waypoints waypoints from a trajectory file.
 *
\author  Mahmoud Ali
\date    3/5/2019
*/

#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"
#include "custom_msgs/state_msg.h"

//#include "normal_toppra_traj_instant_3.h"
#include "test_trajectory_1.h"
//#include "test_trajectory_max_jrk.h"



int main(int argc, char **argv)
{
    ros::init(argc, argv, "cmd_pos_publisher");
    ros::NodeHandle nh;
    ros::Publisher cmd_pos_pub = nh.advertise<std_msgs::Float64MultiArray>("cmd_pos", 1000);
    ros::Publisher state_pub = nh.advertise<custom_msgs::state_msg>("jug", 1000);


    //============ read trajectory ==========
    trajectory_msgs::JointTrajectory  traj;
    custom_msgs::state_msg state_msg;

    for(int j=1; j<4; j++){
        state_msg.header.stamp = ros::Time::now();
        state_msg.pos.clear();
        state_msg.vel.clear();
        state_msg.acc.clear();
        state_msg.jrk.clear();
        for(int jt=1; jt<4; jt++){
            state_msg.pos.push_back(1*jt);
            state_msg.vel.push_back(2*jt);
            state_msg.acc.push_back(3*jt);
            state_msg.jrk.push_back(4*jt);
        }
        ros::Rate init_delay( 1);
        init_delay.sleep();
        state_pub.publish(state_msg);
    }




    traj = generate_traj();
    int n_jts = traj.joint_names.size();
    int n_pts = traj.points.size();
    ROS_INFO_STREAM( "number of joints, and points: "<< n_jts << ", "<<n_pts );
    ros::Rate init_delay( 1);
    init_delay.sleep();

    // variables
    std::vector< std::vector<double> > P_jt_wpt;
    P_jt_wpt.resize( n_jts);
    for(int jt=0; jt<n_jts; jt++){
        for(int pt=0; pt<n_pts; pt++){
            P_jt_wpt[jt].push_back( traj.points[pt].positions[jt] );
        }
    }


    std::vector<double> T_wpt;
    T_wpt.resize(n_pts);
    for(int pt=0; pt<n_pts; pt++)
        T_wpt[pt] = traj.points[pt].time_from_start.toSec()*1e-9 ;

    // message for sending waypoints one by one
    std_msgs::Float64MultiArray msg;

//    for (unsigned long pt=0; pt<n_pts; pt++)
//    {
//        msg.data.clear();
//        for (int jt=0; jt<6; jt++)
//            msg.data.push_back(P_jt_wpt[jt][pt]);
//        cmd_pos_pub.publish(msg);
//        ROS_INFO_STREAM( "pt: "<< pt << ", T: " << T_wpt[pt] << ",  value: "<< P_jt_wpt[4][pt] );
//        ros::spinOnce();
//        ros::Rate loop_rate(  1/T_wpt[pt]);
//        loop_rate.sleep();
//    }

    //try to send one way point, not full trajectory
    msg.data.clear();
    for (int jt=0; jt<6; jt++)
        msg.data.push_back(.1*jt + .4);
    cmd_pos_pub.publish(msg);


    return 0;
}

