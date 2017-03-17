#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Table.h"

using namespace std;

int main()
{
	Table tb("disk", 256, 128, "flatfile", "indexfile");
	tb.Build_Table("data.txt");
	string x;
	cout << "Enter the Date: ";
	cin >> x;
	cout << endl;
	tb.Search(x);
}
