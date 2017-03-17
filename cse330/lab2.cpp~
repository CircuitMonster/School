/*
Name: Brian Ackley
Class: CSE 330
Professor: Kerstin Voigt
Lab #2
*/


#include "Vector.h"
#include <iostream>
using namespace std;

void sieve(Vector<int> & values)
{
   unsigned int max = values.size();
   int i;

   //first initialize all cells
   for (i = 0; i < max; i++)
   {
      values[i] = i;
   }

   //now search for non-zero cells
   for (i = 2; i*i <= max; i++)
   {
      if (values[i] != 0)
      {
	 //inv: i has no factors
	 for (int j = i + i; j < max; j += i)
	 {
	    values[j] = 0;
	 }
	 //inv: all multiples of i have been cleared
      }
      //inv: all nonzero values smaller than i are prime 
   }
   //inv: all nonzero values are prime
}

int main()
{
   int N;

   cout << endl;
   cout << "Prime numbers 1 up to which value? ";
   cin >> N;

   Vector<int> nums;
  
   for (int i = 0; i <= N; i++)
      nums.push_back(i);

   sieve(nums);

   cout << "The prime numbers 1 to " << N << ": ";
   cout << endl << endl;
   for (int i = 1; i < nums.size(); i++)
      cout << nums[i] << " ";

      cout << endl << endl;
}
