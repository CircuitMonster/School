//Brian Ackley
//CSE 455
//Program 5

#include <iostream>
#include <cmath>

using namespace std;

class Simpson
{
public:
	double width(double x_high, double x_low);
	double function(double x_low, double width);
};

double Simpson::width(double x_high, double x_low)
{
	double n = 10000.0;
	double w = 0.0;

	w = ((x_high - x_low) / n);
}

double Simpson::function(double x_low, double width)
{
	double n = 10000.0;
	double w = width;
	double Fx = 0.0;
	double e = 2.7182;
	double pi = 3.14159;
	double sum = 0.0;

	for(double i = 1.0; i <= (n-1.0); i++)
	{
	double xi = (x_low + (w * i));
		if (fmod(i, 2.0) == 0.0)
		{
			4.0 * xi;
		}
		else
		{
			2.0 * xi;
		}
		Fx = ((1.0 / sqrt(2.0 * pi)) * pow (e, ((-(xi * xi))/2.0)));
		sum += Fx * w;
	}
	return sum;
}

int main()
{
	Simpson s;
	double x_low = -10.0;

	for (int i = 0; i < 3; i++)
	{
		double x_high = 0.0;
		cout << "enter in your value for x high" << endl;
		cin >> x_high;

		cout << s.width(x_high, x_low) << endl;

		cout << s.function(x_low, s.width(x_high, x_low)) << endl;
	}
}
