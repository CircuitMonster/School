#include <iostream>
#include "Number.h"

using namespace std;

int main(int argc, char * argv[])
{
    cout << "Enter a number: ";
    int n;
    cin >> n;
    cout << "\nThe prime numbers less then " << n << " are the following:\n";
    for (int k = 2; k < n; ++k)
    {
	Number number(k);
	if (number.isPrime())
	{
	    cout << k << " ";
	}   
    }	
    cout << "\n";
}
