cmake_minimum_required(VERSION 3.0.2)
project(obsAv)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
)
catkin_package(
  CATKIN_DEPENDS roscpp std_msgs sensor_msgs
)
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(obsAv src/obsAv.cpp)
target_link_libraries(obsAv ${catkin_LIBRARIES})

