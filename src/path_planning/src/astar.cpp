//ros libraries
#include "ros/ros.h"
#include "nav_msgs/OccupancyGrid.h"
#include "std_msgs/Int8MultiArray.h"
//c++ libraries
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <sstream>
#include <list>
#include <string>
//opencv libraries
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace std;
using namespace cv;


struct node{
  node()
  {
    x=0;
    y=0;
    f=0;
    g=0;
    h=0;
  }
node *parent;
int x,y;
float f,g,h;
};
node least_f_node(list<node> &l)
{
  node output();
  int n=l.size();
  int n1=n/2;
  if(n==1)
  {
    return l.pop();
  }
  if(n==2)
  {
    if(l.at(0).f>l.at(1).f)
      return l.at(1);
    else
      return l.at(0);
  }
  return output;
}
void path_plan(nav_msgs obstacle_map,int s_x, int s_y,int d_x, int d_y)
{
  list<node> open_nodes;
  list<node> closed_nodes;
  node start();
  start.x=s_x;
  start.y=s_y;

  open_nodes.push_back(start);
  cout<<open_nodes.size();

  while(open_nodes.size()!=0)
  {
    node current;
    for(list<node>::iterator listIterator = open_nodes.begin();
      listIterator != open_nodes.end();listIterator++)
    {
      (*listIterator)
    }

  }


}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}