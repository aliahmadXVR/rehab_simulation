/**
 * @file tf_listner.cpp
 * @author Ali Ahmad (ali.ahmad@xavor.com)
 * @date 2022-02-24
 * 
 * DESCRIPTION:
 * This node is just simple TF listener used for debuging 
 * process duing simulation runs.
 * 
 */
#include <ros/ros.h>
#include <tf/transform_listener.h>
using namespace std;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  tf::TransformListener listener;

  ros::Rate rate(10.0);
  while (node.ok()){
    tf::StampedTransform transform;

/*  try 
    {
      listener.waitForTransform(destination_frame, original_frame, ros::Time(0), ros::Duration(10.0) );
      listener.lookupTransform(destination_frame, original_frame, ros::Time(0), transform);
    } 
    catch (tf::TransformException ex) 
    {
      ROS_ERROR("%s",ex.what());
    }*/

    try
    {
      ros::Time now = ros::Time::now();

      listener.waitForTransform("/map", "/base_link",
                              now, ros::Duration(3.0));
      listener.lookupTransform("/map", "/base_link",  
                              now, transform);
    }
    

    catch (tf::TransformException ex)
    {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    cout<<"______________________________________"<<endl;
    /*cout<<"--Linear--"<<endl;
    cout<<"X: "<<transform.getOrigin().x() <<endl;
    cout<<"Y: "<<transform.getOrigin().y() <<endl;
    cout<<"Z: "<<transform.getOrigin().z() <<endl;
    */
    cout<<"--Angular--"<<endl;
    cout<<"X: "<<transform.getRotation().x() <<endl;
    cout<<"Y: "<<transform.getRotation().y() <<endl;
    cout<<"Z: "<<transform.getRotation().z() <<endl;
    cout<<"______________________________________"<<endl;

    rate.sleep();
  }
  return 0;
};