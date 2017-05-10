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
    //parent=NULL;
  }
};
void path_plan(nav_msgs::OccupancyGrid msg)
{
  //nav_msgs::OccupancyGrid obstacle_map,int s_x, int s_y,int d_x, int d_y
  cout<<"path_start                                     here"<<endl;
  int s_x=11; int s_y=11;;int d_x=30; int d_y=34;
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
  int initial_h=round(sqrt(pow((s_x - d_x),2)+pow((s_y - d_y),2)*10));
  start->h=initial_h;
  start->f=0;
  open_nodes.push_back(start);
  int count=0;
  node *before_c;
  before_c=start;
  while(!open_nodes.empty())
  {
   node  *current;
   //current = new node;
   cout<<"present current x and y "<<before_c->x<<" "<<before_c->y<<endl;
   cout<<"present current g h and f value "<<before_c->g<<" "<<before_c->h<<" "<<before_c->f<<endl;
    for(list<node*>::iterator listIterator = open_nodes.begin();
      listIterator != open_nodes.end();listIterator++)
    {
      if(((listIterator)==(open_nodes.begin()))||(*listIterator)->f<current->f)
      {
        current=(*listIterator);
      }
    }
    cout<<"after update current x and y "<<current->x<<" "<<current->y<<endl;
    cout<<"after update current g h and f value "<<current->g<<" "<<current->h<<" "<<current->f<<endl;
    open_nodes.remove(current);
    cout<<"open nodes size "<<open_nodes.size()<<endl;
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
        if(n_x>=0&&n_y>=0&&n_x<height&&n_y<width)
        {
          float dis_parent,dis_goal;
          dis_parent=sqrt(pow(i,2)+pow(j,2))*10;
          dis_goal=sqrt(pow((n_x-d_x),2)+pow((n_y-d_y),2))*10;
          successor->x=n_x;
          successor->y=n_y;
          successor->g=round(current->g+dis_parent);
          successor->h=round(dis_goal);
          successor->f=successor->h+successor->g;
          cout<<"successor g h and f value "<<successor->g<<" "<<successor->h<<" "<<successor->f<<endl;
          cout<<"successor x and y "<<successor->x<<" "<<successor->y<<endl;
          if(n_x==d_x&&n_y==d_y)
          {
            closed_nodes.push_back(current);
            closed_nodes.push_back(successor);
            goto endloop;
          }
          if(count>0)
          {
            for(list<node*>::iterator listIterator = open_nodes.begin();
              listIterator != open_nodes.end();listIterator++)
            {
              if(current->x==successor->x&&current->y==successor->y&&current->f<=successor->f)
              {
                cout<<"going to start explore"<<endl;
                goto start_explore;
              }
            } 
            for(list<node*>::iterator listIterator = closed_nodes.begin();
              listIterator != closed_nodes.end();listIterator++)
            {
              if(current->x==successor->x&&current->y==successor->y&&current->f<=successor->f)
              {
                cout<<"going to start explore"<<endl;
                goto start_explore;
              }
            }
          }
          open_nodes.push_back(successor);
          count++;
          start_explore:;
          cout<<"count value "<<count<<endl;
        }
      }
    }
    cout<<"successor_out"<<endl;
    cout<<"closed_nodes size"<<closed_nodes.size()<<endl;
    closed_nodes.push_back(current);
    before_c=current;
  }
  endloop: ;

  cout<<"closed nodes size "<<closed_nodes.size()<<endl;
  cout<<"destination_reached"<<endl;
  //cout<<"closed_nodes parents exploring ";
  /*for(list<node*>::iterator listIterator = closed_nodes.begin();
    listIterator != closed_nodes.end();listIterator++)
  {
    cout<<(*listIterator)->x<<(*listIterator)->y<<" ";
  }
  cout<<endl;
  cout<<"closed_nodes parents exploring ";
  for(list<node*>::iterator listIterator = closed_nodes.begin();
    listIterator != closed_nodes.end();listIterator++)
  {
    cout<<(*listIterator)->parent->x<<(*listIterator)->parent->y<<" ";
  }
  cout<<endl;*/
    
  node *destination_node;
  //destination_node = new node;
  destination_node=closed_nodes.back();
  cout<<"path_trace ";
  cout<<destination_node->x<<destination_node->y<<" ";
   while(true)
  {
    destination_node=destination_node->parent;
    cout<<destination_node->x<<destination_node->y<<" ";
    if((destination_node->x==s_x)&&(destination_node->y==s_y))
      goto plotted;
  }
  plotted:;
  cout<<endl;
  node *path_node;
  path_node=closed_nodes.back();
   cv::Mat path_map = cv::Mat::zeros(height,width,CV_8UC3);
   while(true)
   {
    int i_= height - path_node->x;//i=x,j=y;
    path_map.at<Vec3b>(i_,path_node->y)[0] = 255;
    path_map.at<Vec3b>(i_,path_node->y)[1] = 255;
    path_map.at<Vec3b>(i_,path_node->y)[2] = 255;
    path_node=path_node->parent;
    if((path_node->x==s_x)&&(path_node->y==s_y))
      goto over;
  }
   over:;
   imshow("path_map",path_map);
   cv::waitKey(1);

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