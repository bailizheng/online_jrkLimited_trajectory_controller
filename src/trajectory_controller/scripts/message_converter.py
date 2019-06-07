#!/usr/bin/env python

import rospy
#import numpy as np
import yaml
from rospy_message_converter import message_converter
import os 

dir_name = os.path.dirname(__file__) 
print dir_name
if dir_name == ".":  # to work with rosrun or ./messsage_converter.py or python message_converter.py
    dir_name = ""
elif dir_name != "":
    dir_name = dir_name + "/"
    
print dir_name
    
path_selection = raw_input("Choose absolute_path (A) or relative_path(R) if the file is in the same directory of that script: ")
if path_selection== 'R':
    file_path = raw_input("Enter yaml_file name \"file_name.yaml\" ")
    yaml_file = dir_name + file_path
elif path_selection== 'A':
    file_path = raw_input("Enter yaml_file path \"/home/......./file_name.yaml\" ")
    yaml_file = file_path

#yaml_file = dir_name + "/normal_toppra_traj.yaml"
func_file = dir_name + yaml_file.split("/")[-1].split(".")[0] +"_instant.h"   
print yaml_file


with open ( func_file, 'w') as h: 
    print>> h,  ("""
    //#include <ros.h>
    #include <trajectory_msgs/JointTrajectory.h>
    #include <trajectory_msgs/JointTrajectoryPoint.h>
    //this script writes cpp file to instantiate JointTrajectory msg from yaml file"
    """)    
    with open( yaml_file, 'r') as f:
        msg_dict = yaml.load(f)
        traj_msg = message_converter.convert_dictionary_to_ros_message('trajectory_msgs/JointTrajectory', msg_dict)   
        print>>h, "trajectory_msgs::JointTrajectory generate_traj( ) \n {"
        print>>h, "trajectory_msgs::JointTrajectory traj; "
        for jt in traj_msg.joint_names:
            print>>h,  ("   traj.joint_names.push_back(\"{}\");" .format(jt) ) ;
        
        

#        print>>h, "traj.joint_names = {"+" {}\.format( ", ".join( repr(" '{}' ".format(e)  for e in traj_msg.joint_names  ) )+"};"
#        .format(", ".join(['"{}"'.format(joint_name) for joint_name in pt.joint_names])))
        
        print>>h,  ("""
        trajectory_msgs::JointTrajectoryPoint pt;  
        // copy info from Python pt to cpp pt
        """ )
        for pt in traj_msg.points:
            print>>h, "pt.positions = {"+"{}".format( ", ".join( repr(e) for e in pt.positions  ) )+"};"
            print>>h, "pt.velocities = {"+"{}".format( ", ".join( repr(e) for e in pt.velocities  ) )+"};"
            print>>h, "pt.accelerations = {"+"{}".format( ", ".join( repr(e) for e in pt.accelerations  ) )+"};"
            print>>h, "pt.time_from_start = ros::Duration( {} );".format(  pt.time_from_start) 
#            print "pt.time_from_start = ros::duration( {} )".format( ", ".join( repr(e) for e in pt.time_from_start  ) )+"};"
            print>>h, "traj.points.push_back(pt);"
            
        print>>h, ("""
          return traj;
        }
        """)
    
print "trajectory instant is generated and saved as {}".format(func_file)  
    
    
    
    
    
    
    
    
    
    
    
    
    