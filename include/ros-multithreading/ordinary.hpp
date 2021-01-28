#ifndef ORDINARY_H_
#define ORDINARY_H_

#include <ros/ros.h>
#include <std_msgs/String.h>

namespace multi_threading
{
    class ordinary
    {
    private:
        /// @brief ROS private node handle
        ros::NodeHandle private_nh_;

        /// @brief ROS global node handle
        ros::NodeHandle global_nh_;

        /// @brief subscriber A
        ros::Subscriber sub_a_;

        /// @brief subscriber B
        ros::Subscriber sub_b_;

    public:
        /// @brief Constructor
        ordinary();

        /// @brief Destructor
        ~ordinary();

        /// @brief Run function
        void run();
    };

} // namespace multi_threading

#endif