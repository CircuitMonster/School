#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(vector<int> & v, int k)
{
	int s = 0;
	int e = v.size();
	int n;
	while (s < e)
	{
		n = (s + e) / 2;
		if (k == v[n])
		{
			return n;
		}
		else if (k < v[n])
		{
			e = n;
		}
		else
		{
			assert(k > v[n]);
			s = n + 1;
		}
	}
	return -1;
}

int main (int argc, char * args[])
{
	vector<int> v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(12);
	v.push_back(15);
	v.push_back(36);

	assert(binary_search(v, -3) == -1);
	assert(binary_search(v, 1) == -1);
	assert(binary_search(v, -3) == 0);
	assert(binary_search(v, 5) == -1);
	assert(binary_search(v, 6) == 1);
	assert(binary_search(v, 7) == 2);
	assert(binary_search(v, 8) == 3);
	assert(binary_search(v, 9) == -1);
	assert(binary_search(v, 12) == 4);
	assert(binary_search(v, 13) == -1);
	assert(binary_search(v, 15) == 5);
	assert(binary_search(v, 16) == -1);
	assert(binary_search(v, 36) == 6);
	assert(binary_search(v, 46) == -1);
	v.clear();
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	assert(binary_search(v, 1) == -1);
	assert(binary_search(v, 2) == 0);
	assert(binary_search(v, 3) == -1);
	assert(binary_search(v, 4) == 1);
	assert(binary_search(v, 5) == -1);
	assert(binary_search(v, 6) == 2);
	assert(binary_search(v, 7) == -1);

	v.clear();
	v.push_back(2);
	v.push_back(4);
	assert(binary_search(v, 1) == -1);
	assert(binary_search(v, 2) == 0);
	assert(binary_search(v, 3) == -1);
	assert(binary_search(v, 4) == 1);
	assert(binary_search(v, 5) == -1);

	cout << .All Test Pass. . << endl;
}

