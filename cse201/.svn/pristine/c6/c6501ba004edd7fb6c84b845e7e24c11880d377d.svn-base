#include <iostream>
#include <cassert>

using namespace std;


bool is_prime(int n)
{
	for (int i = 2; i < n; ++i)
	{
		int remainder = n % i;
		if (remainder == 0)
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char * args[])
{
	cout << "Enter a number: ";
	int n;
	cin >> n;
	cout << "The prime numbers from 2 to " <<  n << " are: ";
	for (int i = 2; i <= n; ++i)
	{
		if (is_prime(i))
		{
			cout << i << " ";
		}
	}
	cout << endl;
}
