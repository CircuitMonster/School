#include <iostream>

using namespace std;

int main(int argc, char * args[])
{
	cout << "Enter a number: ";	
	int n;
	cin >> n;
	
	for(int i = 2; i <= (n - 1); ++i)
	{
		if(n % i == 0)

		{
			cout << n << " is not Prime." << endl;
			return 0;
		}
	 }
	cout << n << " is Prime." << endl;
}
