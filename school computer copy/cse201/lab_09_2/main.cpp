#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using namespace std;

long sort(vector<int> & v)
{
	long innerLoopCount = 0;
	for ( int i =0; i < v.size() -1; ++i)
	{	
		int k = i;
		for ( int j = i +1; j < v.size(); ++j)
		{	
			++ innerLoopCount;
			if (v[j] < v [k]) 
			{			
				k=j;
		
			}

		
		int temp = v[i];
		v [i] = v[k];
		v[k] = temp;	
		}
	
	}
	return innerLoopCount;
}

int main(int argc, char * argv[])
{	

	srand(time(0));
	vector <int> v( 10000);
	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(rand());
	}
	cout << sort(v)<< endl;
}

