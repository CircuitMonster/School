#include <iostream>
#include <string>
using namespace std;

string fun(int i)
{  //restart();
	static int QS=0;
	switch(QS){
	  case 0: goto Q0; case 1: goto Q1; case 2: goto Q2; case 3: goto Q3;
	}
   Q0:;//end restart()
   while(i != 2)
   {
	QS=1; return "no two yet"; Q1: ; // resume("no two yet");
   }
   QS=2; return "two"; Q2:; //resume("two");
   while(true)
   {
	QS=3; return "there was a two"; Q3: ; // resume("there was a two");
   }
}


int main()
{
   int in;
   cout << "Input whole numbers:" << endl;
   cin >> in;

   while(in != 99){
	cout << fun(in) << endl << "Next?" <<endl;
	cin >> in;
   }
}

