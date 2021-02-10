#include "ros-multithreading/multi_callback_multi_spinners_unblock.hpp"


namespace multi_threading
{
    ros_node::ros_node()
    :   private_nh_(ros::NodeHandle("~")),
        global_nh_(ros::NodeHandle()),
        nh_a_(ros::NodeHandle()),
        nh_b_(ros::NodeHandle())
    {
        // Setup queue_a_ and queue_b_ for respective node handle
        nh_a_.setCallbackQueue(& queue_a_);
        nh_b_.setCallbackQueue(& queue_b_);

        // Instantiate ROS sub_a_
        sub_a_ = nh_a_.subscribe<std_msgs::String>("topic_a", 1, 
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
        sub_b_ = nh_b_.subscribe<std_msgs::String>("topic_b", 1, 
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
        ros::AsyncSpinner spinner_a(1, & queue_a_);
        ros::AsyncSpinner spinner_b(1, & queue_b_);

        // Start spinner
        spinner_a.start();
        spinner_b.start();

        // Main thread do something
        while(ros::ok())
        {
            ROS_INFO_STREAM(ros::this_node::getName() << " main_thread does its job!");
            // Sleep for 5 seconds
            ros::Duration(5).sleep();
        }
    }
} // namespace multi_threading
