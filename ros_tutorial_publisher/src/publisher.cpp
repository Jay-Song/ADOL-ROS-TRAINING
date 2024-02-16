#include <ros/ros.h> // ROS basic header file
#include <ros_tutorial_msgs/IntString.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "topic_publisher"); // Initialize node name
  ros::NodeHandle nh; // Node handle line for communication with ROS system
  // Create publisher ros_topic_pub. The topic name is "ros_tutorial_msg",
  // This means setting the publisher queue size to 100.
  ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorial_msgs::IntString>("/ros_tutorial_msg", 100);
  // Set the loop period. “10” refers to 10Hz and repeats at 0.1 second intervals.
  ros::Rate loop_rate(10);
  // Declare a message called msg in std_msgs/String message file format
  ros_tutorial_msgs::IntString msg;

  int count = 0;

  while (ros::ok())
  {
    std::string hello_msg = "Hello"; // make a variable for the data of the message
    msg.count = count; // Put the variable value into the data of the message
    msg.str_msg = hello_msg;
    ROS_INFO("%d: %s", count, hello_msg.c_str()); // print the data and roop count
    ros_tutorial_pub.publish(msg); // issue a message
    loop_rate.sleep(); // Enters sleep according to the loop cycle determined above
    count++;
  }
  return 0;
}
