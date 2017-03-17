#include <iostream>

using namespace std;

/*
Test cases:

5:  2 3
7:  2 3 5
10: 2 3 5 7
13: 2 3 5 7 11 13

*/


int main(int argc, char * args[])
{
	cout << "Enter a number: ";	
	int n;
	cin >> n;
	
	for(int i = 2; i <= (n - 1); ++i)
	{
		bool iIsPrime = true;
		for (int j = 2; j < i; ++j)
		{
			int remainder = i % j;
			if (remainder == 0)
			{
				iIsPrime = false;
			}
		}
	if (iIsPrime)
	{
		cout << i << " ";
	}
	}
}
