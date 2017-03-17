/*
Name: Brian Ackley
CSE 330
Lab 8
*/


#include "Set.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  Set<int> myset;
  int next;

  for (int i = 0; i< 5; i++)
    {
      cout << endl;
      cout << "[integer] ";
      cin >> next;
      myset.insert(next);
    }

  vector<int> allvals;
  cout << endl << endl;
  myset.print(allvals);
  cout << endl << endl;

   cout << "Set Size is: " << myset.size() << endl;

//excercise 2:
   int s;
   for(int i = 0; i < 4; i++)
   {
      cout << "Enter integer to be searched for: ";
      cin >> s;
      
      if (myset.find(s))
         cout << "found" << endl;
      else
         cout << "not found" << endl;
   }

  
  return 0;
}



