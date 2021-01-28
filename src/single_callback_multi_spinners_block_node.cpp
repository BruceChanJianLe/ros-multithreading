#include "ros-multithreading/single_callback_multi_spinners_block.hpp"


int main(int argc, char ** argv)
{
    // Init ROS node
    ros::init(argc, argv, "single_callback_multi_spinners_node");

    // Instantiate node obj
    multi_threading::ros_node node;

    // Ruun node
    node.run();

    return 0;
}