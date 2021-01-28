#include <ros/ros.h>
#include <std_msgs/String.h>


int main(int argc, char ** argv)
{

    // Init ROS node
    ros::init(argc, argv, "topic_publisher_node");

    ros::NodeHandle global_nh;

    // Create topic_a and topic_b msg
    std_msgs::String msg_a, msg_b;
    msg_a.data = "AAA";
    msg_b.data = "BBB";

    // Create publishers
    auto pub_a = global_nh.advertise<std_msgs::String>("topic_a", 1);
    auto pub_b = global_nh.advertise<std_msgs::String>("topic_b", 1);

    // Set node sleep rate
    ros::Rate r(1);

    while(global_nh.ok())
    {
        // Publish topics
        pub_a.publish(msg_a);
        pub_b.publish(msg_b);

        // Good practice
        ros::spinOnce();

        // Sleep
        r.sleep();
    }

    return 0;
}