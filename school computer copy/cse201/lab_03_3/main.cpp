#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char * args[])
{
	srand(time(0));
	for(int i = 0; i < 100; ++i)
	{
		cout << rand() << endl;
	}
	cout << "Ok." << endl;
}
