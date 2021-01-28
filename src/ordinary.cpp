#include "ros-multithreading/ordinary.hpp"


namespace multi_threading
{
    ordinary::ordinary()
    :   private_nh_(ros::NodeHandle("~")),
        global_nh_(ros::NodeHandle())
    {
        // Instantiate ROS sub_a_
        sub_a_ = global_nh_.subscribe<std_msgs::String>("topic_a", 1, 
            [this](const std_msgs::String::ConstPtr & msg)
            {
                // Sleep for 3 second
                ros::Duration(3).sleep();
                ROS_INFO_STREAM(ros::this_node::getName() << " topic_a says: " << msg->data.c_str());
            }
        );

        // Instantiate ROS sub_b_
        sub_b_ = global_nh_.subscribe<std_msgs::String>("topic_b", 1, 
            [this](const std_msgs::String::ConstPtr & msg)
            {
                ROS_INFO_STREAM(ros::this_node::getName() << " topic_b says: " << msg->data.c_str());
            }
        );
    }


    ordinary::~ordinary()
    {
    }


    void ordinary::run()
    {
        ros::spin();
    }
} // namespace multi_threading
