#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void append(vector<int> & v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
	}
}

int main(int argc, char * args[])
{

	vector<int> v;

	assert(v.size() == 0);

	v.push_back(9);
	v.push_back(9);
	v.push_back(9);

	assert(v.size() == 3);

	// v = (9, 9, 9)
	assert(v[0] == 9);
	assert(v[1] == 9);
	assert(v[2] == 9);
	append(v, 4);
	
	// v = (9, 9, 9, 0, 1, 2, 3)
	assert(v.size() == 7);

	assert(v[0] == 9);
	assert(v[1] == 9);
	assert(v[2] == 9);
	assert(v[3] == 0);
	assert(v[4] == 1);
	assert(v[5] == 2);
	assert(v[6] == 3);

	cout << "All Test Pass." << endl;
}
