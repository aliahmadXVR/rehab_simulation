/**
 * @file findpoint.cpp
 * @author Ali Ahmad (ali.ahmad@xavor.com)
 * @date 2022-02-24
 * 
 * DESCRIPTION:
 * Simple program that tells whether a point
 * falls inside a rectangle. Not used anywhere 
 * for simulation purposes.
 */

#include "iostream"
#include "ros/ros.h"

using namespace std;


class COORDINATE
{
    private:

    int x1 = 0, y1 = 0, x2 = 10, y2 = 10;
    


    public:
    int x = 0, y = 0;
    
    bool FindPoint(int x, int y)
    {
        if (x > x1 and x < x2 and y > y1 and y < y2)
            return true;
    
        return false;
    }
};




int main(int argc, char **argv)
{

    ros::init(argc, argv, "findpoint");
    ros::NodeHandle n;
    COORDINATE point;

    while(1)
    {
        cout<<"-----Enter X=0 & Y=0 for EXIT-----"<<endl;
        cout<<"Enter X: ";
        cin>>point.x;
        cout<<"Enter Y: ";
        cin>>point.y;

        if (point.x == 0 && point.y == 0 ) 
        break;

        if ( point.FindPoint(point.x, point.y) )
            cout << "Yes"<<endl;
        else
            cout << "No"<<endl;
    }
    
   ros::spinOnce();
   return 0;
}
