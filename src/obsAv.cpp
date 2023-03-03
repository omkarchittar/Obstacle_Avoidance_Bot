#include <obsAv.h>
#include <ros/ros.h>


// to turn the robot left: Publishing positive angular velocity on the topic cmd_vel 
void obsAv::turnLeft() {
  ros::Rate rate(10);
    vel.linear.x = 0;
    vel.angular.z = 0.5;
    ROS_DEBUG_STREAM("Forward velocity= " << vel.linear.x <<
    ", Turn velocity=" << vel.angular.z);
    pub.publish(vel);
    ROS_INFO_STREAM("Turning Left");
}

// to turn the robot right: Publishing negative angular velocity on the topic cmd_vel 
void obsAv::turnRight() {
  ros::Rate rate(10);
    vel.linear.x = 0;
    vel.angular.z = -0.5;
    ROS_DEBUG_STREAM("Forward velocity= " << vel.linear.x << ", Turn velocity=" << vel.angular.z);
    pub.publish(vel);
    ROS_INFO_STREAM("Turning Right");
}

// to move robot in forward: Publishing positive linear velocity on the topic cmd_vel 
void obsAv::moveForward() {
  ros::Rate rate(10);
  vel.angular.z = 0;
  vel.linear.x = 0.3;
  ROS_DEBUG_STREAM("Forward velocity= " << vel.linear.x << ", Turn velocity=" << vel.angular.z);
  pub.publish(vel);
  ROS_INFO_STREAM("Moving Forward");
}

// Subscriber Callback for Lidar sensor.
void obsAv::LaserscanCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
  if (msg->ranges[330] < 0.3 || msg->ranges[0] < 0.3)
    turnLeft();
  else if (msg->ranges[30] < 0.3)
    turnRight();
  else
    moveForward();
}


int main(int argc, char **argv) {
  ros::init(argc, argv, "obsAv");

  // Object of class obsAv to call constructor and start moving the robot
  obsAv bot;

  ros::spin();
  return 0;
}
