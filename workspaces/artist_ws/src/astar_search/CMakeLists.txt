cmake_minimum_required(VERSION 2.8.3)
project(astar_search)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  turtlebot3_gazebo
)

catkin_python_setup()

catkin_package(
   CATKIN_DEPENDS roscpp rospy std_msgs turtlebot3_gazebo geometry_msgs
)

catkin_install_python(PROGRAMS
  nodes/test
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

