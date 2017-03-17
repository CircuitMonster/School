// Random.cpp

#include <cassert>
#include "Random.h"

using namespace std;

void rand_seed()
{
  int seed = static_cast<int>(time(0));
  srand(seed);
}

// random integer between a and b;
int rand_int(int a, int b)
{
  return a + rand() % (b - a + 1);
}

// k random integers 1 to number upto ->  vector v;

void random_vector(int k, int upto, vector<int>& v)
{
  rand_seed();

  assert(v.empty());

  for (int i = 1; i <= k; i++)
	v.push_back(rand_int(1,upto));

  return;
}

