/**
 * @file findPersonLoc_in_map.cpp
 * @author Ali Ahmad (ali.ahmad@xavor.com)
 * @date 2022-02-24
 * 
 * DESCRIPTION:
 * This node subscribes to the /person_loc topic which is publishing 
 * the person location in camera frame a.k.a  "/azure_link". The node transforms
 * the point in the map frame and displays the location of person in map. 
 * In later stages, this node will subscribe to the person location topic 
 * provided by AI team and the same process will be done on that point. 
 */

#include "iostream"
#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PointStamped.h"
#include <tf/transform_listener.h>
#include <cmath>
#include "rehab_robot/location_info.h"
#include "rehab_robot/time_info.h"

using namespace std;


class MAP_TAG
{
    private:
    
    struct COORDINATE
    {
        double x1;
        double y1;
        double x2;
        double y2;
    }kitchen,lounge,entrance,tvRoom,bedRoom,lobby;
 

    public:

    MAP_TAG()
    {
        //Add the coordinates of the locations in map here//
        kitchen.x1  = 4.23; kitchen.y1  = 1.46;  kitchen.x2  = 7.46;   kitchen.y2  = 4.94;
        lounge.x1   = 1.66; lounge.y1   = 1.52;  lounge.x2   = 4.22;   lounge.y2   = 7.49;
        entrance.x1 = 0;    entrance.y1 = 0;     entrance.x2 = 1.58;   entrance.y2 = 6.85;
        lobby.x1    = 5.22; lobby.y1    = 4.81;  lobby.x2    = 7.1;    lobby.y2    = 7.3;
        tvRoom.x1   = 0.52; tvRoom.y1   = 7.57;  tvRoom.x2   = 4.63;   tvRoom.y2   = 12.12; 
        bedRoom.x1  = 5.2;  bedRoom.y1  = 7.4;   bedRoom.x2  = 8.9;    bedRoom.y2  = 12.1;
        cout<<"Coordinates of MAP Initilized"<<endl;
    }

    geometry_msgs::PoseStamped goal_loc_map;

   
    struct TIME_TRACK
    {
        double kitchen;
        double lounge;
        double entrance;
        double lobby;
        double tvRoom;
        double bedRoom;
        double away;
    }person_time;
    
    bool FindGoal_loc(double x, double y)
    {
        if (x > kitchen.x1 and x < kitchen.x2 and y > kitchen.y1 and y < kitchen.y2)
        {
          
          loc_info.person_location = "Inside Kitchen";
          //cout<<"Person is *Inside Kitchen"<<endl;
        }

        else if (x > lounge.x1 and x < lounge.x2 and y > lounge.y1 and y < lounge.y2)
        {
         
          loc_info.person_location = "Inside Lounge";
          //cout<<"Person is *Inside Lounge"<<endl;        
        }
        
        else if (x > entrance.x1 and x < entrance.x2 and y > entrance.y1 and y < entrance.y2)
        {
          
          loc_info.person_location = "At Entrance";
          //cout<<"Person is *At Entrance"<<endl;
        }
        
        else if (x > lobby.x1 and x < lobby.x2 and y > lobby.y1 and y < lobby.y2)
        {
          
          loc_info.person_location = "Inside Lobby";
          //cout<<"Person is *Inside Lobby"<<endl; 
        }

        else if (x > tvRoom.x1 and x < tvRoom.x2 and y > tvRoom.y1 and y < tvRoom.y2)
        {
         
          loc_info.person_location = "Inside TvRoom";
          //cout<<"Person is *Inside TV Room"<<endl;
        }

        else if (x > bedRoom.x1 and x < bedRoom.x2 and y > bedRoom.y1 and y < bedRoom.y2)
        {
          
          loc_info.person_location = "Inside BedRoom";
          //cout<<"Person is *Inside Bedroom"<<endl;
        }
        
        else 
        {
          
          loc_info.person_location = "Away";
          //cout<<"--Away--"<<endl;
        }
    }// 


} robot;

void goalCallback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{  
    robot.goal_loc_map.pose.position.x = msg->pose.position.x;
    robot.goal_loc_map.pose.position.y = msg->pose.position.y;

}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "label_goal");
    ros::NodeHandle n;
    ros::Subscriber robot_sub = n.subscribe("/move_base_simple/goal", 1000,goalCallback);

    ros::Publisher location_pub = n.advertise<rehab_robot::location_info>("/location_tag", 1000);
    
    ros::Rate loop_rate(10);
    unsigned int seq = 0;
    
    cout<<"Publishers and Subscribers Initialized"<<endl;

    
    
    //Timing Part
    
    robot.FindGoal_loc(robot.goal_loc_map.point.x,robot.goal_loc_map.point.y);
    

    ros::spinOnce();
    loop_rate.sleep();
    }
    return 0;
}
