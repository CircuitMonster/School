#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "Random.h"

using namespace std;


/*
template <class T>
void heap_sort(vector<T>& vec)
{
	PriorityQueue<T> sorter;

	for (int i = 0; i < vec.size(); i++)
		sorter.push(vec[i]);

	T next;
	int i = vec.size()-1;
	while (!sorter.empty())
	{
		next = sorter.top();
		sorter.pop();
		vec[i] = next;
		i--;
	}
}


int main()
{
	vector<int> nums;
	int next;
	for (int i = 1; i < 10; i++)
	{
		cout << endl << "Integer: ";
		cin >> next;
		nums.push_back(next);
	}

	heap_sort(nums);

	cout << endl << endl;
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl << endl;

	system("PAUSE");
	return 0;
}
*/


int main()
{
  PriorityQueue<int> myq;

  // enter several values into myq;
  
  cout << endl;
  cout << "How many values? ";
  int k;
  cin >> k;

  vector<int> myinputs;
  random_vector(k,100,myinputs);
  print_vector(myinputs);

  /* ... old manual entry ...
  for (int i = 1; i <= k; i++)
    {
      int next;
      // produce a next value
	  cout << "Integer: ";
	  cin >> next;
      cout << endl;
      // enter it into myq;

      myq.push(next);

    }
  */

  for (int i = 0; i < myinputs.size(); i++)
	  myq.push(myinputs[i]);

  // print out the contents of myq;
  // PriortyQueue has a function for this ...
  myq.print_tree();

  myq.pop();

  cout << endl << endl;
  myq.print_tree();



  return 0;
}
