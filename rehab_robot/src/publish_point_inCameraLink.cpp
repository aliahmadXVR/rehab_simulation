/**
 * @file publish_point_inCameraLink.cpp
 * @author Ali Ahmad (ali.ahmad@xavor.com)
 * @date 2022-02-24
 * 
 * DESCRIPTION:
 * This node publishes a point in front of robot at certain distance
 * in camera frame a.k.a "/azure_link". This point is subscribed by
 * findPersonLoc_in_map node to find the location of person in map.
 * In future this node will not be used and the AI team will publish 
 * the person location in camera frame.
 * 
 */
#include "ros/ros.h"
#include "geometry_msgs/PointStamped.h"


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher person_Loc_pub = n.advertise<geometry_msgs::PointStamped>("/person_loc", 1000);

  ros::Rate loop_rate(10);
  unsigned int seq = 0;

  int count = 0;
  while (ros::ok())
  {
    geometry_msgs::PointStamped person_location;

    person_location.header.seq = seq;
    ++seq;
    person_location.header.frame_id = "/azure_link"; 
    person_location.header.stamp = ros::Time::now();
    person_location.point.x = 1.82;  // 1.82m = 6 ft , assuming person standing in front of robot at 6 ft.
    person_location.point.y = 0 ;
    person_location.point.z = 0 ;  

    //publish person location
    person_Loc_pub.publish(person_location);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}