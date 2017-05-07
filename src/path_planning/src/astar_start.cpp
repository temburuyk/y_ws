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
 
node *parent;
int x,y;
float f,g,h;
 node()
  {
    x=0;
    y=0;
    f=0;
    g=0;
    h=0;
  }
};
/*node *least_f_node(list<node*> &l)
{
  node  *current;
  for(list<node*>::iterator listIterator = l.begin();
    listIterator != l.end();listIterator++)
  {
    if(((*listIterator)->x==(l.begin())->x)&&((*listIterator)->y==(l.begin())->y)||(*listIterator)->f<current->f)
    {
      current=(*listIterator);
    }
  }
  return current;
}*/
void path_plan(nav_msgs::OccupancyGrid msg)
{
  //nav_msgs::OccupancyGrid obstacle_map,int s_x, int s_y,int d_x, int d_y
  cout<<"path_start"<<endl;
  int s_x=1; int s_y=1;int d_x=2; int d_y=3;
  int height=msg.info.height;int width=msg.info.width;
   nav_msgs::OccupancyGrid obstacle_map;
    obstacle_map.header.stamp = ros::Time::now();
    obstacle_map.header.frame_id = "/path_map";
    obstacle_map.info.resolution = msg.info.resolution;
    obstacle_map.info.origin.position.x = 0.0;
    obstacle_map.info.origin.position.y = 0.0;
    obstacle_map.info.origin.position.z = 0.0;
    obstacle_map.info.origin.orientation.x = 0.0;
    obstacle_map.info.origin.orientation.y = 0.0;
    obstacle_map.info.origin.orientation.z = 0.0;
    obstacle_map.info.origin.orientation.w = 1.0;
    obstacle_map.info.width = width;
    obstacle_map.info.height = height;
    obstacle_map.info.map_load_time = ros::Time::now();
   for(int i=0;i<height;i++)//initialising map
    {
       for(int j=0;j<width;j++)
        {
           obstacle_map.data.push_back(0);
        }
    }

    //cout<<"2"<<endl;

  list<node*> open_nodes;
  list<node*> closed_nodes;
  node *start;
  start = new node;
  start->x=s_x;
  start->y=s_y;
  start->g=0;
  start->h=round(sqrt((s_x - d_x)^2+(s_y - d_y)^2)*10);
  start->f=0;
  open_nodes.push_back(start);
  cout<<"open nodes size "<<open_nodes.size()<<endl;
  int count=0;
  while(!open_nodes.empty())
  {
   node  *current;
   current = new node;
  for(list<node*>::iterator listIterator = open_nodes.begin();
    listIterator != open_nodes.end();listIterator++)
  {
    if(((listIterator)==(open_nodes.begin()))||(*listIterator)->f<current->f)
    {
      current=(*listIterator);
    }
  }
    open_nodes.remove(current);
    for(int i=-1;i<2;i++)
    {
      for(int j=-1;j<2;j++)
      {
        //cout<<j<<" "<<i<<endl;
        node *successor;
        successor = new node;
        successor->parent=current;
        int n_x,n_y=0;
        n_x=current->x+j;
        n_y=current->y+i;
        float dis_parent,dis_goal;
        dis_parent=sqrt(i^2+j^2)*10;
        dis_goal=sqrt((n_x-d_x)^2+(n_y-d_y)^2)*10;
        successor->x=n_x;
        successor->y=n_y;
        successor->g=round(current->g+dis_parent);
        successor->h=round(dis_goal);
        successor->f=successor->h+successor->g;
        if(n_x==d_x&&n_y==d_y)
        {
          closed_nodes.push_back(current);
          closed_nodes.push_back(successor);
          goto endloop;
        }
        //cout<<"che1"<<endl;
        //cout<<open_nodes.size()<<endl;
        if(count>0)
        {
          //cout<<"che"<<endl;
          for(list<node*>::iterator listIterator = open_nodes.begin();
            listIterator != open_nodes.end();listIterator++)
          {
            //cout<<current->x<<endl;
            //cout<<successor->x<<endl;
            if(current->x==successor->x&&current->y==successor->y&&current->f<successor->f)
            {
              goto start_explore;
            }
          } 
          for(list<node*>::iterator listIterator = closed_nodes.begin();
            listIterator != closed_nodes.end();listIterator++)
            //cout<<current->x<<endl;
          //cout<<successor->x<<endl;
          {
            if(current->x==successor->x&&current->y==successor->y&&current->f<successor->f)
            {
              goto start_explore;
            }
          }
        }
        //cout<<"che2"<<endl;
        open_nodes.push_back(successor);
        count++;
        //cout<<"che4"<<endl;
        start_explore:;
        cout<<"came to start explore"<<endl;
        cout<<"count value "<<count<<endl;
      }
    }
    cout<<"succesor_out"<<endl;
    closed_nodes.push_back(current);
  }
  endloop: ;

  cout<<"closed nodes size "<<closed_nodes.size()<<endl;
  cout<<"destination_reached"<<endl;
  node *destination_node;
  destination_node = new node;
  destination_node=closed_nodes.back();
  cout<<"path_trace ";
  cout<<destination_node->x<<destination_node->y<<" ";
  node *path_trace;
    path_trace = new node;
  while(true)
  {
    path_trace=destination_node->parent;
    cout<<path_trace->x<<path_trace->y<<" ";
    if((path_trace->x==s_x)&&(path_trace->y==s_y))
      goto plotted;
  }
  plotted:;
  cout<<endl;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  //ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
   cout<<"1"<<endl;
    ros::NodeHandle n1;
    ros::Subscriber path_sub=n1.subscribe<nav_msgs::OccupancyGrid>("/scan/local_map",25,path_plan);
   //path_plan(obstacle_map,1,1,3,2);
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}