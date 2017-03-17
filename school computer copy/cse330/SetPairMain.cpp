#include <iostream>
#include <string>
#include <set>
#include "Pair.h"
using namespace std;

int main()
{
   set<Pair<string, int> > basket;

   string f;
   int k;
   
   for (int i = 1; i <= 5; i++)
   {
      cout << "fruit: ";
      cin >> f;
      cout << endl;
      cout << "How Many? ";
      cin >> k;

      Pair<string, int> next(f, k);
      basket.insert(next);
   }

   set<Pair<string, int> >::iterator itr = basket.begin();
   
   for (;itr != basket.end(); itr++)
   {
      cout << (*itr).first << " : " << (*itr).second << endl;
   }
   cout << endl << endl;

   return 0;
}
