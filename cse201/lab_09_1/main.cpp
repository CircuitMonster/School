#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

void mysort(vector<int> & v)
{
	for ( int i =0; i < v.size() -1; ++i)
	{	
		int k = i;
		for ( int j = i +1; j < v.size(); ++j)
	{	
			if (v[j] < v [k]) k=j;
	}

		int temp = v[i];
		v [i] = v[k];
		v[k] = temp;
	}
}

int main(int argc, char * argv[])
{	
	vector <int> v;
	v.push_back (4);
	v.push_back (3);
	v.push_back (9);
	v.push_back (1);

	mysort(v);
	assert(v[0] == 1);
	assert(v[1] == 3);
	assert(v[2] == 4);
	assert(v[3] == 9);

	cout << "All tests passed." << endl;
	return 0;
}
