# ROS Multithreading

This repository is currently undergoing construction. Please come back again later.  

In ROS there are two types of objects handling callbacks:

- Spinner
- Callback Queue

**Spinner:** Spinner object has the ability to call callback message contained in a callback queue.  
**Callback Queue:** Callback queue object appends an callback message to its queue.  

An ordinary ROS node with two subscribers.  
![img](resources/ordinary.png)

## Multiple Queues

This method is generally preferred. Having multiple queues and threads to handle each callback.

A ROS

## Multiple Callback

Allowing multiple threads to preform same callback at the same time.

## Reference

- http://wiki.ros.org/roscpp/Overview/Callbacks%20and%20Spinning
- https://answers.ros.org/question/56275/suggest-good-example-of-multi-threading-with-ros/
- https://answers.ros.org/question/53055/ros-callbacks-threads-and-spinning/
- https://answers.ros.org/question/185153/ros-multithreading-example/
- https://roboticsbackend.com/ros-asyncspinner-example/
- https://levelup.gitconnected.com/ros-spinning-threading-queuing-aac9c0a793f

