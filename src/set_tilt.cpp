#include "ros/ros.h"
//#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "set_tilt");
  if (argc != 3)
  {
    ROS_INFO("Set Rehab Robot Motor Tilt");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<gazebo::set_model_configuration>("set_tilt");
  gazebo::set_model_configuration srv;
  //srv.request.a = atoll(argv[1]);
  //srv.request.b = atoll(argv[2]);
  /*if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }*/

  return 0;
}