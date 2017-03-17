/*
Name: Brian Ackley
Class: CSE 330
Professor: Kerstin Voigt
Assignment 1
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


   //Assignment 1 test:gedit

   //erase function test:
   int i = 1;
   while(i < nums.size())
   {
      if (nums[i] == 0)
         nums.erase(i);
      else
         i++;
   }   
      
   cout << "The prime numbers 1 to " << N << ": ";
   cout << endl << endl;
   for (int i = 1; i < nums.size(); i++)
      cout << nums[i] << " ";

      cout << endl << endl;


   //insert function test:
   int nsize = nums.size()-2;
   for(int i = nsize; i >= 1 ; i--)
   {
      int temp = nums[i] - nums[i+1];
      nums.insert(i+1,temp);
   }

   cout << "The prime numbers 1 to " << N << " ,with the difference: ";
   cout << endl << endl;
   for (int i = 1; i < nums.size(); i++)
      cout << nums[i] << " ";

      cout << endl << endl;
}
