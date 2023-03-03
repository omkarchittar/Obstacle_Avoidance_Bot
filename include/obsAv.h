#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>

#pragma once
class obsAv {
  public: 
    ros::NodeHandle n;  // Main access point for communicating with the ROS system.
    ros::Publisher pub;
    ros::Subscriber sub;
    geometry_msgs::Twist vel;

    // Constructor for class obsAv
    obsAv() {
      pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 10);
      sub = n.subscribe("scan", 10, &obsAv::LaserscanCallback, this);
    }

    // Commands turtlebot to turn left.  
    void turnLeft();

    // Commands turtlebot to turn right. 
    void  turnRight();

    // Commands turtlebot to move forward. 
    void moveForward();

    // Callback for topic "scan" subscriber.
    void LaserscanCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
};
