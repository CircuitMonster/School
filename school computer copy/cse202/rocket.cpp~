// File: rocket.cpp
// By: Brian Ackley
// Project: lab3
// Program displays a rocket moving in different directions

#include "ccc_win.h"

using namespace std;

class Rocket
{
public:
   Rocket();	//Default
   Rocket(Point loc);	//Constructor
   void display();
   void move(int dx, int dy);
   void change_direction(string new_direction){direction = new_direction;}
private:
   Point llc;
   string direction;
   void displayup();
   void displaydown();
   void displayright();
   void displayleft();
};

Rocket::Rocket()
{
   llc = Point(0,0);
   direction="up";
}

Rocket::Rocket(Point loc)
{
   llc = loc;
   direction = "up";
}

void Rocket::display()
{
   if(direction=="up")
         {
                displayup();
         }
   if(direction=="right")
         {
                displayright();
         }
   if(direction=="left")
         {
                displayleft();
         }
} 

void Rocket::displayup()
{
   Point p1(llc);
   Point p2 = p1;
     p2.move(0,15);
   Point p3 = p2;
     p3.move(5,0);
   Point p4 = p3;
     p4.move(0, -15);
   Point p5 = p2;
     p5.move(2.5, 5);

   Line l1 = Line(p1, p2);
   Line l2 = Line(p2, p3);
   Line l3 = Line(p3, p4);
   Line l4 = Line(p4, p1);
   Line l5 = Line(p2, p5);
   Line l6 = Line(p3, p5);

   cwin << l1 << l2 << l3 << l4 << l5 << l6;
}

void Rocket::displayright()
{
   Point p1(llc);
   Point p2 = p1;
     p2.move(0,5);
   Point p3 = p2;
     p3.move(15,0);
   Point p4 = p3;
     p4.move(0,-5);
   Point p5 = p3;
     p5.move(5, -2.5);

   Line l1 = Line(p1, p2);
   Line l2 = Line(p2, p3);
   Line l3 = Line(p3, p4);
   Line l4 = Line(p4, p1);
   Line l5 = Line(p3, p5);
   Line l6 = Line(p4, p5);

   cwin << l1 << l2 << l3 << l4 << l5 << l6;
}

void Rocket::displayleft()
{
  Point p1(llc);
   Point p2 = p1;
     p2.move(0,5);
   Point p3 = p2;
     p3.move(-15,0);
   Point p4 = p3;
     p4.move(0,-5);
   Point p5 = p3;
     p5.move(-5, -2.5);

   Line l1 = Line(p1, p2);
   Line l2 = Line(p2, p3);
   Line l3 = Line(p3, p4);
   Line l4 = Line(p4, p1);
   Line l5 = Line(p3, p5);
   Line l6 = Line(p4, p5);

   cwin << l1 << l2 << l3 << l4 << l5 << l6;
}

void Rocket::move(int dx, int dy)
{
   llc.move(dx, dy);
}

int ccc_win_main()
{
   cwin.coord(0, 1000, 1000, 0);
   Rocket usa1(Point(250, 10));
   Rocket usa2(Point(750, 10));
   usa1.display();
   usa2.display();
   
   for (int i = 0; i <= 1000; i +=150)
   {
      usa1.move(0, i);
      usa2.move(0, i);
      usa1.change_direction("right");
      usa2.change_direction("left");
      usa1.display();
      usa2.display();
   }
   return 1;
}
