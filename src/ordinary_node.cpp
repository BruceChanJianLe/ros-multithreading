#include "ros-multithreading/ordinary.hpp"


int main(int argc, char ** argv)
{
    // Init ROS node
    ros::init(argc, argv, "ordinary_node");

    // Instantiate node obj
    multi_threading::ordinary node;

    // Ruun node
    node.run();

    return 0;
}