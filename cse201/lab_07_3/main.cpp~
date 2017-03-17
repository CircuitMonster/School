#include <iostream>
#include <cassert>
#include <vector>

 

using namespace std;

 

void append(vector<int> & v, int k)

{
	v.push_back(k);
	int positionOfK = v.size() - 1;
	while (positionOfK > 0 && v[positionOfK -1] > v[positionOfK])
	{
		v[positionOfK] = v[positionOfK - 1];
		v[positionOfK - 1] = k;
		--positionOfK;
	}
}
 
int main(int argc, char * args[])
{

	vector<int> v;

	v.push_back(3);
	v.push_back(6);
	v.push_back(7);
	v.push_back(12);
	assert(v.size() == 4);

        insert(v, 8);

	assert(v.size() == 5);
	assert(v[0] == 3);
	assert(v[1] == 6);
	assert(v[2] == 7);
	assert(v[3] == 8);
	assert(v[4] == 12);
 
	cout << "All Test Pass." << endl;

}


