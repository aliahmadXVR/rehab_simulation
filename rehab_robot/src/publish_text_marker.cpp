#include "ros/ros.h"
#include "visualization_msgs/Marker.h"


visualization_msgs::Marker kitchen_marker;
visualization_msgs::Marker lounge_marker;
visualization_msgs::Marker entrance_marker;
visualization_msgs::Marker lobby_marker;
visualization_msgs::Marker tvroom_marker;
visualization_msgs::Marker bedroom_marker;

void init_markers()
{
    lounge_marker.header.frame_id = "map";
    lounge_marker.header.stamp = ros::Time();
    lounge_marker.ns = "my_namespace";
    lounge_marker.id = 0;
    lounge_marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    lounge_marker.action = visualization_msgs::Marker::ADD;
    lounge_marker.pose.position.x = 2.6;
    lounge_marker.pose.position.y = 3.8;
    lounge_marker.pose.position.z = 0;
    lounge_marker.pose.orientation.x = 0.0;
    lounge_marker.pose.orientation.y = 0.0;
    lounge_marker.pose.orientation.z = 0.0;
    lounge_marker.pose.orientation.w = 1.0;
    lounge_marker.scale.x = 0.7;
    lounge_marker.scale.y = 0.7;
    lounge_marker.scale.z = 0.7;
    lounge_marker.color.a = 1.0;
    lounge_marker.color.r = 1.0;
    lounge_marker.color.g = 1.0;
    lounge_marker.color.b = 0.0;
    lounge_marker.text = "LOUNGE";

    kitchen_marker.header.frame_id = "map";
    kitchen_marker.header.stamp = ros::Time();
    kitchen_marker.ns = "my_namespace";
    kitchen_marker.id = 0;
    kitchen_marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    kitchen_marker.action = visualization_msgs::Marker::ADD;
    kitchen_marker.pose.position.x = 6.4;
    kitchen_marker.pose.position.y = 2.4;
    kitchen_marker.pose.position.z = 0;
    kitchen_marker.pose.orientation.x = 0.0;
    kitchen_marker.pose.orientation.y = 0.0;
    kitchen_marker.pose.orientation.z = 0.0;
    kitchen_marker.pose.orientation.w = 1.0;
    kitchen_marker.scale.x = 0.7;
    kitchen_marker.scale.y = 0.7;
    kitchen_marker.scale.z = 0.7;
    kitchen_marker.color.a = 1.0;
    kitchen_marker.color.r = 1.0;
    kitchen_marker.color.g = 1.0;
    kitchen_marker.color.b = 0.0;
    kitchen_marker.text = "KITCHEN";

    entrance_marker.header.frame_id = "map";
    entrance_marker.header.stamp = ros::Time();
    entrance_marker.ns = "my_namespace";
    entrance_marker.id = 0;
    entrance_marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    entrance_marker.action = visualization_msgs::Marker::ADD;
    entrance_marker.pose.position.x = 0.9;
    entrance_marker.pose.position.y = 4.2;
    entrance_marker.pose.position.z = 0;
    entrance_marker.pose.orientation.x = 0.0;
    entrance_marker.pose.orientation.y = 0.0;
    entrance_marker.pose.orientation.z = 0.0;
    entrance_marker.pose.orientation.w = 1.0;
    entrance_marker.scale.x = 0.7;
    entrance_marker.scale.y = 0.7;
    entrance_marker.scale.z = 0.7;
    entrance_marker.color.a = 1.0;
    entrance_marker.color.r = 1.0;
    entrance_marker.color.g = 1.0;
    entrance_marker.color.b = 0.0;
    entrance_marker.text = "ENTRANCE";


    lobby_marker.header.frame_id = "map";
    lobby_marker.header.stamp = ros::Time();
    lobby_marker.ns = "my_namespace";
    lobby_marker.id = 0;
    lobby_marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    lobby_marker.action = visualization_msgs::Marker::ADD;
    lobby_marker.pose.position.x = 6.2;
    lobby_marker.pose.position.y = 5.5;
    lobby_marker.pose.position.z = 0;
    lobby_marker.pose.orientation.x = 0.0;
    lobby_marker.pose.orientation.y = 0.0;
    lobby_marker.pose.orientation.z = 0.0;
    lobby_marker.pose.orientation.w = 1.0;
    lobby_marker.scale.x = 0.7;
    lobby_marker.scale.y = 0.7;
    lobby_marker.scale.z = 0.7;
    lobby_marker.color.a = 1.0;
    lobby_marker.color.r = 1.0;
    lobby_marker.color.g = 1.0;
    lobby_marker.color.b = 0.0;
    lobby_marker.text = "LOBBY";

    tvroom_marker.header.frame_id = "map";
    tvroom_marker.header.stamp = ros::Time();
    tvroom_marker.ns = "my_namespace";
    tvroom_marker.id = 0;
    tvroom_marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    tvroom_marker.action = visualization_msgs::Marker::ADD;
    tvroom_marker.pose.position.x = 1.6;
    tvroom_marker.pose.position.y = 9.1;
    tvroom_marker.pose.position.z = 0;
    tvroom_marker.pose.orientation.x = 0.0;
    tvroom_marker.pose.orientation.y = 0.0;
    tvroom_marker.pose.orientation.z = 0.0;
    tvroom_marker.pose.orientation.w = 1.0;
    tvroom_marker.scale.x = 0.7;
    tvroom_marker.scale.y = 0.7;
    tvroom_marker.scale.z = 0.7;
    tvroom_marker.color.a = 1.0;
    tvroom_marker.color.r = 1.0;
    tvroom_marker.color.g = 1.0;
    tvroom_marker.color.b = 0.0;
    tvroom_marker.text = "TVROOM";

    bedroom_marker.header.frame_id = "map";
    bedroom_marker.header.stamp = ros::Time();
    bedroom_marker.ns = "my_namespace";
    bedroom_marker.id = 0;
    bedroom_marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
    bedroom_marker.action = visualization_msgs::Marker::ADD;
    bedroom_marker.pose.position.x = 6.2;
    bedroom_marker.pose.position.y = 9.1;
    bedroom_marker.pose.position.z = 0;
    bedroom_marker.pose.orientation.x = 0.0;
    bedroom_marker.pose.orientation.y = 0.0;
    bedroom_marker.pose.orientation.z = 0.0;
    bedroom_marker.pose.orientation.w = 1.0;
    bedroom_marker.scale.x = 0.7;
    bedroom_marker.scale.y = 0.7;
    bedroom_marker.scale.z = 0.7;
    bedroom_marker.color.a = 1.0;
    bedroom_marker.color.r = 1.0;
    bedroom_marker.color.g = 1.0;
    bedroom_marker.color.b = 0.0;
    bedroom_marker.text = "BEDROOM";

}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "text_marker_pub");

  ros::NodeHandle n;

  ros::Publisher lounge_pub = n.advertise<visualization_msgs::Marker>("/lounge_marker", 1000);
  ros::Publisher kitchen_pub = n.advertise<visualization_msgs::Marker>("/kitchen_marker", 1000);
  ros::Publisher entrance_pub = n.advertise<visualization_msgs::Marker>("/entracne_marker", 1000);
  ros::Publisher lobby_pub = n.advertise<visualization_msgs::Marker>("/lobby_marker", 1000);
  ros::Publisher tvroom_pub = n.advertise<visualization_msgs::Marker>("/tvroom_marker", 1000);
  ros::Publisher bedroom_pub = n.advertise<visualization_msgs::Marker>("/bedroom_marker", 1000);

  init_markers();

  ros::Rate loop_rate(10);
  unsigned int seq = 0;

  while (ros::ok())
  {
    
    lounge_pub.publish( lounge_marker );
    kitchen_pub.publish( kitchen_marker);
    entrance_pub.publish( entrance_marker );
    lobby_pub.publish( lobby_marker );
    tvroom_pub.publish( tvroom_marker );
    bedroom_pub.publish( bedroom_marker );




    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}