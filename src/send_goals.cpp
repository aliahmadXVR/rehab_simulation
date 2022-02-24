/**
 * @file send_goals.cpp
 * @author Ali Ahmad (ali.ahmad@xavor.com)
 * @date 2022-02-24
 * 
 * DESCRIPTION:
 * This node is just a test node, not being used anymore. 
 * This node was used for sending the goals to move_base 
 * after subscribing the gazebo_states.
 * 
 */
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "gazebo_msgs/ModelStates.h"


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
using namespace std;

void gazeboModelsates_callback(const gazebo_msgs::ModelStates::ConstPtr& msg)
{
  /*  cout<<"Barrel Position"<<endl;
    cout<<msg->pose[3].position.x<<endl;
    cout<<msg->pose[3].position.y<<endl;
    cout<<msg->pose[3].position.z<<endl;
*/
//tell the action client that we want to spin a thread by default
    static MoveBaseClient ac("move_base", true);

    //wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0)))
    {
    ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    //we'll send a goal to the robot to move 1 meter forward
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    goal.target_pose.pose.position.x = 5.0;
    goal.target_pose.pose.position.y = 5.0;
    goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    /*ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward");
    else
    ROS_INFO("The base failed to move forward 1 meter for some reason");
*/


}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_navigation_goals");

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/gazebo/model_states", 1000, gazeboModelsates_callback);

    
    ros::spin();
    return 0;
} 