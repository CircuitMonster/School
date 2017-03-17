/* 
Name: Brian Ackley
Date: 1-24-13
Assignment 1
File: assignment1.cpp
Description: Program shows an item drop from an altitude and then has a parachute deploy at a given time.
             the program also displays when the parchute deploys, and the ending velocity of the object.
*/

#include "ccc_win.h"

using namespace std;

class Parachute
{
public:
   Parachute();
   Parachute(Point a, Point b, Point c);
   void display() const;
   void move(int dx, int dy);

private:
   Point p1;
   Point p2;
   Point p3;
};

Parachute::Parachute()
{
   p1 = Point(0,0);
   p2 = Point(0,10);
   p3 = Point(10,0);
}

Parachute::Parachute(Point a, Point b, Point c)
{
   p1 = a;
   p2 = b;
   p3 = c;
}

void Parachute::display() const
{
   cwin << Line(p1, p2);
   cwin << Line(p2, p3);
   cwin << Line(p3, p1);
}

void Parachute::move(int dx, int dy)
{
   p1.move(dx, dy);
   p2.move(dx, dy);
   p3.move(dx, dy);
}

int ccc_win_main()
{
  int velocity = 0;
  int time = 0;
  int opentime = 6;
  int speed = 100;
  int altitude = 1000;
  cwin.coord (-100, altitude, altitude, -100);
  Circle c(Point(100, altitude), 30);
  cwin << c;
  Parachute dp(Point(c.get_center().get_x()-50, c.get_center().get_y()), Point(c.get_center().get_x()+50,
     c.get_center().get_y()), Point(c.get_center().get_x(), c.get_center().get_y()+50));
  while (altitude >= 0)		//checks altitude above 0/ ground
  {
     if (time < opentime)	//checks before parachute deploys
     {
        velocity += 32;
	if (velocity >= 174)	//checks terminal velocity
	{
	   velocity = 174;
	}
     }
     else	//check when parachute deploys
     {
	speed -= 20;
	if (speed <= 0)		//checks speed with chute
	{
	   speed = 0;
	}
	velocity -= 100;	//checks velocity with chute
	if (velocity < 17)
	{
	   velocity = 17;
	}
	if (time==opentime)
	{
	   cwin << Message(Point(c.get_center().get_x()-300, c.get_center().get_y()+20), "Chute Open!");
	}
        dp.display();	//displays parachute

     }
     c.move(speed, -velocity);		//updates circles location
     cwin << c;		//displays circle
     altitude = altitude-velocity;	//updates altitude
     time++;		//incriments time
     dp.move(speed, -velocity);		//updates parachute location
  }
 
 Line s(Point(0, 0), Point(1000, 0));	//Ground line
 cwin << s ;
 cwin << Message(Point(c.get_center().get_x()-600, 0), "Landing Velocity: 17ft/sec");
 
 return 0;

}
  
