#include <iostream>

using namespace std;

/*
Test cases:

2:  2
4:  2 2
6:  2 3
8:  2 2 2
12: 2 2 3
16: 2 2 2 2
18: 2 3 3
24: 2 2 2 3

*/

int main(int argc, char * args[])
{
	cout << "Enter a number: ";	
	int n;
	cin >> n;
	

	while(true)
	{
		for (int i = 2; i <= n; ++i)
		{
			if (n % i == 0)
			{
				cout << " " << i;
				n = n/i;
				break;
			}
		}
		if (n == 1)
		{
			break;
		}
	}
	cout << endl;
}
