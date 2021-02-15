#include "ros-multithreading/multi_callback_multi_spinners_unblock_alt.hpp"


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

        // Start new threads
        thread_list_.emplace_back(std::thread(
            [this]()
            {
                // Setup thread spinner
                ros::SingleThreadedSpinner spinner_a;

                // Start spinner
                spinner_a.spin(& this->queue_a_);
            }
        ));

        thread_list_.emplace_back(std::thread(
            [this]()
            {
                // Setup thread spinner
                ros::SingleThreadedSpinner spinner_b;

                // Start spinner
                spinner_b.spin(& this->queue_b_);
            }
        ));
    }

    ros_node::~ros_node()
    {
        // Wait for child thread to join
        for(auto & thread : this->thread_list_)
        {
            if(thread.joinable())
                thread.join();
        }
    }

    void ros_node::run()
    {
        // Main thread do something
        while(ros::ok())
        {
            ROS_INFO_STREAM(ros::this_node::getName() << " main_thread does its job!");
            // Sleep for 5 seconds
            ros::Duration(5).sleep();
        }
    }
} // namespace multi_threading
