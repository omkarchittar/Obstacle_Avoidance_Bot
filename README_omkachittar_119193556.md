# **ENPM690 Homework 3**

# obsAv
Sumilation of turtlebot3 burger avoiding obstacles in a closed environment.

## Overview
The task involves showcasing a basic obstacle avoidance functionality using a lidar sensor within the ROS-gazebo framework. Once the turtlebot identifies an obstacle within a specific distance, it halts forward movement, steers left or right until the obstacle is out of range, and then resumes forward motion.

To accomplish this, the 'obsAv' node subscribes to the 'scan' topic, receives laser data, and then decides on the appropriate action to take based on whether an obstacle is detected. It then publishes velocity commands to the 'cmd_vel' topic to move the robot ahead, turn left, or turn right.

Link to Autonomous Navigation Video - https://youtu.be/8jOTACZnwRA

## **File Tree**

```
omkarchittar_119193556
+-obsAv
  +- include
    +- obsAv.h
  +- launch
    +-obsAv.launch
  +- rviz
    +-obsAv.rviz
  +-src
    +-obsAv.cpp
  +- CMakeLists.txt
  +- package.xml
+-README_omkarchittar_119193556.txt
```

## **Installation and Running**
## Dependencies
- ROS - Noetic
- Gazebo
- [turtlebot3_simulations](https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git)


## Building and Running
1) Extract all the files in the src folder of your workspace
    cd ~/<your_ws>/src

2) Build the package: 
   ```bash
    sudo apt install ros-noetic-turtlebot3-simulations
    echo "export TURTLEBOT3_MODEL=burger" >> ~/.bashrc
    
    catkin_make
    ```

3) To operate the teleop feature, we must execute two commands. Since the turtlebot3 package is already installed, these commands can be used directly. The first command will launch the world file used for autonomous navigation, while the second command will launch the file responsible for controlling teleop operations.

    Here are the commands(run them in separate terminals):
        roslaunch turtlebot3_gazebo turtlebot3_world.launch
        roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch

4) For the autonomous navigation of the turtlebot in the gazebo world, obsAv node for obstacle avoidance and RViz to visualize Robot Model and sensor data:
    ```bash
    cd ~/<your_ws>
    source devel/setup.bash
    roslaunch obsAv obsAv.launch
    ```
    You sholud be able to see Turtlebot moving in the gazebo world, avoiding obstacles, and also visualize the Robot Model and laser data in RViz.



