#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"
//#include "normal_toppra_traj_instant_3.h"
#include "test_trajectory_1.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "cmd_pos_publisher");
    ros::NodeHandle nh;
    ros::Publisher cmd_pos_pub = nh.advertise<std_msgs::Float64MultiArray>("cmd_pos", 1000);


    //============ read trajectory ==========
    trajectory_msgs::JointTrajectory  traj;
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
    for (unsigned long pt=0; pt<n_pts; pt++)
    {        
        msg.data.clear();
        for (int jt=0; jt<6; jt++)
            msg.data.push_back(P_jt_wpt[jt][pt]);
        cmd_pos_pub.publish(msg);
        ROS_INFO_STREAM( "pt: "<< pt << ", T: " << T_wpt[pt] << ",  value: "<< P_jt_wpt[4][pt] );
        ros::spinOnce();
        ros::Rate loop_rate(  1/T_wpt[pt]);
        loop_rate.sleep();

    }


    return 0;
}

