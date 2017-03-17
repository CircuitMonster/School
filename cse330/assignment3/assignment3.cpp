/*
Name: Brian Ackley
CSE 330
Assignment 3
*/

#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

template <class T>
void treesort(vector<T>& vec)
{
  set<int> myset;
  for(int i= 0; i < vec.size(); i++)
  {
    myset.insert(vec[i]);
  }
  vec.clear();
  set<int>::iterator itr;
  for(itr= myset.begin(); itr != myset.end(); itr++)
  {
    vec.push_back(*itr);
  }
}

void rand_seed();
int rand_int(int, int);
void random_vector(int, int, vector<int>&);

int main()
{
   for(int i= 0; i < 3; i++)
  {
     int k;
     int n;
     vector<int> vec;
     cout << "Enter Size of Vector ";
     cin >> k;
     cout << "Random numbers from 1 to: ";
     cin >> n;

     cout << "Vector with random numbers: ";
     random_vector(k,n,vec);
     for(int i= 0; i < vec.size(); i++)
    {
       cout << vec[i] << " ";
    }

    cout << endl;
 
    cout << "Vector sorted: ";
    treesort(vec);
    for(int j= 0; j < vec.size(); j++)
   {
      cout << vec[j] << " ";
   }
 
   cout << endl << endl;
  }
}



void rand_seed()
{
  int seed = static_cast<int>(time(0));
  srand(seed);
}

int rand_int(int a, int b)
{
  return a + rand() % (b - a + 1);
}

void random_vector(int k, int upto, vector<int>& v)
{
  rand_seed();

  assert(v.empty());

  for (int i = 1; i <= k; i++)
    v.push_back(rand_int(1,upto));

  return;
}
