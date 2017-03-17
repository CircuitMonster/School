#include <iostream>
using namespace std;

int main()
{
   int sz;

   cout << endl;
   cout << "Size of array: ";
   cin >> sz;

   int a[sz];

   for(int i = 0; i < sz; i++)
   {
      cout << endl;
      cout << "[integer] ";
      cin >> a[i];
   }

   cout << endl << endl;

   int * p;
   
   p = &a[0];
   for(int i = 1; i <= sz; i++)
   {
      cout << *p << " ";
      p++;
   }

/*   for(int i = 0; i < sz; i++)
   {
      cout << a[i] << endl;
   }
*/

      cout << endl << endl;
}
