#include <iostream>

using namespace std;

#define SIGMA(s,a,i,n) for(i=1,s=0.0;i<=(n);s+=(a),i++)

main()
{
	int i;
	float sum;

	SIGMA(sum, i, i, 10);
	cout << sum <<endl;

	SIGMA(sum, i*i, i, 10);
	cout << sum <<endl;

	double H10;
	SIGMA(H10, 1.0/i, i, 10);
	cout << Hn <<endl;

}

