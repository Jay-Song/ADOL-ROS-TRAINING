#include <ros/ros.h> // ROS basic header file
#include <ros_tutorial_msgs/Addition.h>
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client");
  ros::NodeHandle nh;
  // Create service client ros_tutorials_service_client. The service name is "/ros_tutorial_srv"
  // this is used to send the request
  ros::ServiceClient ros_tutorials_service_client = nh.serviceClient<ros_tutorial_msgs::Addition>("/ros_tutorial_srv");

  // Create srv instance by using ros_tutorial_msgs/Addition
  ros_tutorial_msgs::Addition srv;

  int num1 = 0;
  int num2 = 0;
  std::string input_str;

  while (ros::ok())
  {
    ROS_INFO("put two numbers (ex: 2 3)");
    getline(std::cin, input_str);

    if (input_str == "exit")
      break;

    std::stringstream ss(input_str);
    ss >> num1; ss >> num2;

    srv.request.a = num1;
    srv.request.b = num2;

    if (ros_tutorials_service_client.call(srv) == true)
    {
      ROS_INFO("send srv, srv.Request.a and b: %d, %d", srv.request.a, srv.request.b);
      ROS_INFO("receive srv, srv.Response.result: %d\n", srv.response.result);
    }
    else
    {
      ROS_ERROR("Failed to call service ros_tutorial_srv");
      return 1;
    }
  }
  return 0;
}