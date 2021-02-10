#include "ros-multithreading/single_callback_multi_spinners_block.hpp"


namespace multi_threading
{
    ros_node::ros_node()
    :   private_nh_(ros::NodeHandle("~")),
        global_nh_(ros::NodeHandle())
    {
        // Instantiate ROS sub_a_
        sub_a_ = global_nh_.subscribe<std_msgs::String>("topic_a", 1, 
            [this](const std_msgs::String::ConstPtr & msg)
            {
                // Sleep for 3 seconds
                ros::Duration(3).sleep();
                ROS_INFO_STREAM(ros::this_node::getName() << " topic_a says: " << msg->data.c_str());
            },
            ros::VoidConstPtr(),
            ros::TransportHints().tcpNoDelay()
        );

        // Instantiate ROS sub_b_
        sub_b_ = global_nh_.subscribe<std_msgs::String>("topic_b", 1, 
            [this](const std_msgs::String::ConstPtr & msg)
            {
                ROS_INFO_STREAM(ros::this_node::getName() << " topic_b says: " << msg->data.c_str());
            },
            ros::VoidConstPtr(),
            ros::TransportHints().tcpNoDelay()
        );
    }

    ros_node::~ros_node()
    {
    }

    void ros_node::run()
    {
        // Set multiple spinners but only one callback queue
        ros::MultiThreadedSpinner spinner(2);
        spinner.spin();
        // Main thread job will never get it chances to print out this message
        ROS_INFO_STREAM(ros::this_node::getName() << " main_thread does it job!");
    }
} // namespace multi_threading
