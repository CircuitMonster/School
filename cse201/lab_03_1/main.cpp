#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char * args[])
{
	// Allocate memory to store 3 floating point values
	double x;
	double y;
	double z;

	cout << "X = ";
	cin >> x;

	cout << "Y = ";
	cin >> y;

	cout << "Z = ";
	cin >> z;

	cout << "X + Y + Z = ";
	cout << ((x + y) + z);
	cout << endl;

	cout << "sin(X) = ";
	cout << sin(x);
	cout << endl;

	cout << "cos((X + Y) / Z) = ";
	cout << cos((x + y) / z);
	cout << endl;

	cout << "The Average of X, Y, and Z = ";
	cout << ((x + y + z) / 3);
	cout << endl;
}
