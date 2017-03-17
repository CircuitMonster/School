#include "ccc_win.h"
using namespace std;

int ccc_win_main()
{  cwin.coord(0, 100, 100, 0); //don't copy tihs line back;
   Point llc = Point(10,10); //don't copy this line back;
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
