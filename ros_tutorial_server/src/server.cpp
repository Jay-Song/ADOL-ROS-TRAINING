#include <ros/ros.h> // ROS basic header file
#include <ros_tutorial_msgs/Addition.h>

bool additionServiceCallback(ros_tutorial_msgs::Addition::Request &req,
                             ros_tutorial_msgs::Addition::Response &res)
{
  res.result = req.a + req.b; // save the addition of request a and b into the response.
  ROS_INFO("received request: x=%d, y=%d", req.a, req.b);
  ROS_INFO("response to send: %d", res.result);
  // A return value of true means the service succeeded,
  // and the response object has been filled with the necessary data. 
  // A return value of false means the call has failed
  // and the response object will not be sent to the caller. 
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server"); // Initialize node name
  ros::NodeHandle nh;                      // Node handle line for communication with ROS system

  // Create service server ros_tutorial_server. The service name is "/ros_tutorial_srv" 
  // this means run additionServiceCallback function when the request exists
  ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("/ros_tutorial_srv", additionServiceCallback);
  ROS_INFO("ready service server!");
  ros::spin(); // waiting service request
  return 0;
}
