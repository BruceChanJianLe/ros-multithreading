cmake_minimum_required(VERSION 3.0.2)
project(ros-multithreading)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES ros-multithreading
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Topic Publisher
add_executable(topic_publisher_node src/topic_publisher_node.cpp)
target_link_libraries(topic_publisher_node ${catkin_LIBRARIES})

# Ordinary ROS node
add_executable(ordinary_node src/ordinary_node.cpp src/ordinary.cpp)
target_link_libraries(ordinary_node ${catkin_LIBRARIES})

# Single Callback Queue & Multiple Spinners block (2)
add_executable(single_cb_multi_sp_block src/single_callback_multi_spinners_block_node.cpp src/single_callback_multi_spinners_block.cpp)
target_link_libraries(single_cb_multi_sp_block ${catkin_LIBRARIES})

# Single Callback Queue & Multiple Spinners unblock (2)
add_executable(single_cb_multi_sp_unblock src/single_callback_multi_spinners_unblock_node.cpp src/single_callback_multi_spinners_unblock.cpp )
target_link_libraries(single_cb_multi_sp_unblock ${catkin_LIBRARIES})