

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


void rand_seed();
int rand_int(int, int);

//classes

class A
{
public:
   A() {}
   void iam() {cout << "A";}
};

int main()
{
 
   int next;
   vector<int> vec;
/*   cout << "[interger] ";

   while (cin >> next)
      {
	vec.push_back(next);
	cout << "[interger] ";
      }
*/

rand_seed();

   for (int i = 1; i <= 10; i++)
    vec.push_back(rand_int(1, 100));
   cout << endl << endl;

   for (int i = 0; i < vec.size(); i++)
   cout << endl << endl;

      cout << vec[i] << " ";
   cout << endl << endl;

   return 0;
}

void rand_seed()
{
   int seed = static_cast<int>(time(0));
   srand(seed);
}
