#include "ros-multithreading/multi_callback_multi_spinners_unblock.hpp"


int main(int argc, char ** argv)
{
    // Init ROS node
    ros::init(argc, argv, "multi_callback_multi_spinners_unblock_node");

    // Instantiate node obj
    multi_threading::ros_node node;

    // Ruun node
    node.run();

    return 0;
}