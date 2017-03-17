/* Unit test of class stack.
*/

#include <iostream>
#include <cassert>

#include "stack.cpp"

using namespace std;

int main()
{

   stack<int> s;

   assert(s.empty());
   cout << "Created an empty stack\n";

   s.push(1);

   assert(s.top()==1);
   cout << "Pushed 1 on top\n";

   s.pop();

   assert(s.empty());
   cout << "Popped 1 off again\n";

   for(int i = 1; i<5; i++)
	s.push(i);

   for(int i = 4; i>0; i--)
   {
	cout << i << " On top?  ";
	assert(s.top()==i);
        cout << "OK!\n";
	s.pop();
   }
   

   cout << "Tests OK\n";

   return 0;
}

