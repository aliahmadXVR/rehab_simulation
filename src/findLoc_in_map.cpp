/**
 * @file findLoc_in_map.cpp
 * @author Ali Ahmad (ali.ahmad@xavor.com)
 * @date 2022-02-24
 * 
 * DESCRIPTION:
 * This node is a test node for finding location of
 * any arbitrary point (assuming to be robot) in map.  
 */
#include "iostream"
#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "math.h"

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
        // Simulation Coordinates //
        kitchen.x1  = 4.23; kitchen.y1  = 1.46;  kitchen.x2  = 7.46;   kitchen.y2  = 4.94;
        lounge.x1   = 1.66; lounge.y1   = 1.52;  lounge.x2   = 4.22;   lounge.y2   = 7.49;
        entrance.x1 = 0;    entrance.y1 = 0;     entrance.x2 = 1.58;   entrance.y2 = 6.85;
        lobby.x1    = 5.22; lobby.y1    = 4.81;  lobby.x2    = 7.1;    lobby.y2    = 7.3;
        tvRoom.x1   = 0.52; tvRoom.y1   = 7.57;  tvRoom.x2   = 4.63;   tvRoom.y2   = 12.12; 
        bedRoom.x1  = 5.2;  bedRoom.y1  = 7.4;   bedRoom.x2  = 8.9;    bedRoom.y2  = 12.1; 

        // Actual Living Lab Coordinates //
        /*kitchen.x1  = -0.2;  kitchen.y1  = -43.5;  kitchen.x2  = -3.5;    kitchen.y2  = -40.5;
        lounge.x1   = -0.3;  lounge.y1   = -46;    lounge.x2   = -6.1;    lounge.y2   = -43;
        entrance.x1 = -2.6;  entrance.y1 = -47.3;  entrance.x2 = -5.6;    entrance.y2 = -45.9; //to be re entered//
        lobby.x1    = -3.6;  lobby.y1    = -43.1;  lobby.x2    = -6.2;    lobby.y2    = -41.1;
        tvRoom.x1   = -6.2;  tvRoom.y1   = -47.2;  tvRoom.x2   = -10.9;   tvRoom.y2   = -43.4; 
        bedRoom.x1  = -6.1;  bedRoom.y1  = -43.0;  bedRoom.x2  = -11.1;    bedRoom.y2 = -39.4; */

    }
   // else if (x < tvRoom.x1 and x > tvRoom.x2 and y < tvRoom.y1 and y > tvRoom.y2)
    //        -8 < -6.2 and -8 > -10.9           -45 < -47.2  and -45 > -43.4    
    //For Simulation//
    bool FindPoint(double x, double y)
    {
        if (x > kitchen.x1 and x < kitchen.x2 and y > kitchen.y1 and y < kitchen.y2)
        cout<<"Robot is *Inside Kitchen"<<endl;

        else if (x > lounge.x1 and x < lounge.x2 and y > lounge.y1 and y < lounge.y2)
        cout<<"Robot is *Inside Lounge"<<endl;        
        
        else if (x > entrance.x1 and x < entrance.x2 and y > entrance.y1 and y < entrance.y2)
        cout<<"Robot is *At Entrance"<<endl;  

        else if (x > lobby.x1 and x < lobby.x2 and y > lobby.y1 and y < lobby.y2)
        cout<<"Robot is *Inside Lobby"<<endl;  

        else if (x > tvRoom.x1 and x < tvRoom.x2 and y > tvRoom.y1 and y < tvRoom.y2)
        cout<<"Robot is *Inside TV Room"<<endl; 

        else if (x > bedRoom.x1 and x < bedRoom.x2 and y > bedRoom.y1 and y < bedRoom.y2)
        cout<<"Robot is *Inside Bedroom"<<endl; 

        else 
        {
            cout<<"--Away--"<<endl;
        }
    }

    //For Actual Scenerio//
    /*bool FindPoint(double x, double y)
    {
        if (x < kitchen.x1 and x > kitchen.x2 and y > kitchen.y1 and y < kitchen.y2)
        cout<<"Robot is *Inside Kitchen"<<endl;

        else if (x < lounge.x1 and x > lounge.x2 and y > lounge.y1 and y < lounge.y2)
        cout<<"Robot is *Inside Lounge"<<endl;        
        
        else if (x < entrance.x1 and x > entrance.x2 and y > entrance.y1 and y < entrance.y2)
        cout<<"Robot is *At Entrance"<<endl;  

        else if (x < lobby.x1 and x > lobby.x2 and y > lobby.y1 and y < lobby.y2)
        cout<<"Robot is *Inside Lobby"<<endl;  

        else if (x < tvRoom.x1 and x > tvRoom.x2 and y > tvRoom.y1 and y < tvRoom.y2)
        cout<<"Robot is *Inside TV Room"<<endl; 

        else if (x < bedRoom.x1 and x > bedRoom.x2 and y > bedRoom.y1 and y < bedRoom.y2)
        cout<<"Robot is *Inside Bedroom"<<endl; 

        else 
        {
            cout<<"--Away--"<<endl;
        }
    }*/
};



//CallBack Function for Subscriber to /rtabmap/localization_pose)
void localization_poseCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    /*cout<<"---Robot Current Position---"<<endl;
    cout<<"X: "<<msg->pose.pose.position.x<<endl;
    cout<<"Y: "<<msg->pose.pose.position.y<<endl;
    cout<<"------"<<endl;*/
    
    MAP_TAG robot;
    robot.FindPoint(msg->pose.pose.position.x,msg->pose.pose.position.y);
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "findLoc_in_map");
    ros::NodeHandle n;
    
    //For Simulation
    ros::Subscriber sub = n.subscribe("/rtabmap/localization_pose", 1000,localization_poseCallback);

    //For Actual Lab
    //ros::Subscriber sub = n.subscribe("/amcl_pose", 1000,localization_poseCallback);

     
   ros::spin();
   return 0;
}
