#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cmd_vel_publisher");
    ros::NodeHandle nh;
    ros::Publisher cmd_vel_pub = nh.advertise<std_msgs::Float64MultiArray>("cmd_vel", 100);

    // message for sending waypoints one by one
    std_msgs::Float64MultiArray msg;
    std::vector< std::vector<double> > vel_pt_jt={{-02,   35,  -25,  5,  30,    20},
                                                  {-15,  -35,   -35,  0,  15,   -5},
                                                  {-05,   00,   -25, -30,  35,   30},
                                                  {  5,   00,   15, -20,  -25,   10}}; //different combinations


//    std::vector< std::vector<double> > vel_pt_jt={{-02,  130,  130,  5,  30,    20},
//                                                  {-15,  130,   130,  0,  15,   -5},
//                                                  {-05,   130,   130, 0,  35,   30},
//                                                  {  5,   00,   -130, -20,  -25,   10}}; //different combinations

//    std::vector< std::vector<double> > vel_pt_jt={{-02,  130,  130,  5,  30,    20},
//                                                  {-15,  -130,   130,  0,  15,   -5},
//                                                  {-05,   130,   -130, 0,  35,   30},
//                                                  {  5,   -130,   130, -20,  -25,   10}}; //different combinations



    double t[]={1.35, 1.4, 5, 1.5}; //time bet. velocities changes
    ros::Duration(1).sleep();
    for (unsigned long pt=0; pt<vel_pt_jt.size(); pt++)
    {
        msg.data.clear();
        for (int jt=0; jt<6; jt++)
            msg.data.push_back( vel_pt_jt[pt][jt]);

        cmd_vel_pub.publish(msg);
        double crnt_t = ros::Time::now().toSec();
        ros::Duration(t[pt]).sleep();
        ROS_INFO_STREAM( "cmd_vel_"<< pt << ": "<< ros::Time::now().toSec() - crnt_t);
        for (int jt=0; jt<6; jt++)
            ROS_INFO_STREAM( "jt_"<< jt <<": "<<  vel_pt_jt[pt][jt]);

//        ros::Rate loop_rate(  1/vel_times[pt]);
//        loop_rate.sleep();
        ros::spinOnce();
    }


    return 0;
}

