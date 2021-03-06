#include <iostream>
#include <cassert>

using namespace std;

int mymaximum(int a[], int numberOfElements)

{
  assert(numberOfElements > 0);
  int largestValue = a[0];
  for( int i = 1; i < numberOfElements; ++i)
    {
      if(a[i] > largestValue)
	{
	  largestValue = a[i];
	}
    }
  return largestValue;
}

int main(int argc, char * args[])
{
  int a[] = {3 , 9, -4, 4 };
  assert(mymaximum(a, 4) ==9);
  
  int b[] = {-4, 4 };
  assert(mymaximum(b, 2) ==4);
  
  int c[] = {-2 };
  assert(mymaximum(c, 1) == -2);
  
  int d[] = {9, 9, 11, 9, 9 };
  assert(mymaximum(d, 5) == 11);
  
  cout << "All tests passed." << endl;


}

