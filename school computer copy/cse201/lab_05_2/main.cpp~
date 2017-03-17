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
		assert(is_prime(2));
		assert(is_prime(3));
		assert(!is_prime(4));
		assert(!is_prime(9));
		assert(!is_prime(50));
		assert(!is_prime(100));

		cout << "All cases pass." << endl;
	}
