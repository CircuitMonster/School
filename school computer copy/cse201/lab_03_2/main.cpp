#include <iostream>

using namespace std;

int main(int argc, char * args[])
{
	double meters = 0;
	int feet = 0;
	int inches = 0;
    
	cout << "Enter Meters: ";
	cin >> meters;

	feet = meters / 0.3048;
	inches = ((meters / 0.3048) * 12 + .5) - feet * 12;

	cout << feet << " ft " << inches << " in\n";
}
