#include <ros/ros.h> // ROS basic header file
#include <std_msgs/Int32.h>

void msgCallback(const std_msgs::Int32::ConstPtr &msg)
{
  ROS_INFO_STREAM("received " << msg->data);
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "topic_subscriber"); // Initialize node name
 ros::NodeHandle nh; // Node handle line for communication with ROS system
 // Create subscriber ros_topic_sub. The topic name is "/ros_tutorial_msg"
 // The queue size is 100 and msgCallback is called when the topic is published. 
 ros::Subscriber ros_tutorial_sub = nh.subscribe("/ros_tutorial_msg", 100, msgCallback);
 ros::spin(); // this function waits the message publishing and calls the callback function.
 return 0;
}
