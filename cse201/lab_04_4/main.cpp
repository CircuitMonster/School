#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char * args[])
{
	srand(time(0));
	
	for (int i = 0; i < 100; ++i)
	{
		for (int n = 0; n < 6; ++n)
		{
			int r = rand() % 16;
			{
				if (r == 0) cout << "0";
				if (r == 1) cout << "1";
				if (r == 2) cout << "2";
				if (r == 3) cout << "3";
				if (r == 4) cout << "4";
				if (r == 5) cout << "5";
				if (r == 6) cout << "6";
				if (r == 7) cout << "7";
				if (r == 8) cout << "8";
				if (r == 9) cout << "9";
				if (r == 10) cout << "A";
				if (r == 11) cout << "B";
				if (r == 12) cout << "C";
				if (r == 13) cout << "D";
				if (r == 14) cout << "E";
				if (r == 15) cout << "F";
			}		
		}
	cout << " " << endl;
	}
	
}
