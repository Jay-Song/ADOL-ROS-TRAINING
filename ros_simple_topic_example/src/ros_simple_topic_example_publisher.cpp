#include <ros/ros.h> // ROS basic header file
#include <std_msgs/Int32.h>

int main(int argc, char **argv)
{
 ros::init(argc, argv, "topic_publisher"); // Initialize node name
 ros::NodeHandle nh; // Node handle line for communication with ROS system
 // Create publisher ros_topic_pub. The topic name is "/ros_tutorial_msg", the queue size is 100.
 ros::Publisher ros_tutorial_pub = nh.advertise<std_msgs::Int32>("/ros_tutorial_msg", 100);

 ros::Rate loop_rate(10);  // Set the loop period. “10” refers to 10Hz.

 std_msgs::Int32 msg;  // Declare a message called msg in std_msgs/String message file format
 int count = 0; // Declare a variable for loop count

 while (ros::ok())
 {
   std::string hello_msg = "Hello"; // make a variable for the data of the message
   msg.data = count; // Put the variable value into the data of the message
   ROS_INFO("%d: %s", count, hello_msg.c_str()); // print the loop count and the data
   ros_tutorial_pub.publish(msg); // issue a message
   loop_rate.sleep(); // Enters sleep according to the loop cycle determined above
   count++;
 }
 return 0;
}
