#include "ros/ros.h"
#include "visualization_msgs/Marker.h"


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "text_marker_pub");

  ros::NodeHandle n;

  ros::Publisher vis_pub = n.advertise<visualization_msgs::Marker>("/text", 1000);

  ros::Rate loop_rate(10);
  unsigned int seq = 0;

  int count = 0;
  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time();
    marker.ns = "my_namespace";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = 1;
    marker.pose.position.y = 1;
    marker.pose.position.z = 1;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 1;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;
    marker.color.a = 1.0;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    marker.text = "Hello World";
    vis_pub.publish( marker );

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}