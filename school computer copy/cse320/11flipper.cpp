#include <iostream>
#include <cassert>

using namespace std;

void flip(int &i)
{
	cout << "          flip start "<<"i="<< i<<"\n";
	i = 2*i;
	cout << "          flip exit  "<<"i="<< i<<"\n";
}

int main()
{
	int j =1;
	cout <<"main j="<<j<<endl;
	flip(j);
	cout <<"main j="<<j<<endl;
	flip(j);
	cout <<"main j="<<j<<endl;
	flip(j);
	cout <<"main j="<<j<<endl;

	assert(j==8);

	return 0;
}

