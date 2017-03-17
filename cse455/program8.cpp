#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <cmath>

using namespace std;

double Numbers [] = {130.0, 650.0, 99.0, 150.0, 128.0, 302.0, 95.0, 945.0, 368.0, 961.0};
double estNumbers [] = {163.0, 765.0, 141.0, 166.0, 137.0, 355.0, 136.0, 1206.0, 433.0, 1130.0};
double actNumbers [] = {186.0, 699.0, 132.0, 272.0, 291.0, 331.0, 199.0, 1890.0, 788.0, 1601.0};

double X [] = {186.0, 699.0, 132.0, 272.0, 291.0, 331.0, 199.0, 1890.0, 788.0, 1601.0};
double Y [] = {15.0, 69.9, 6.5, 22.4, 28.4, 65.9, 19.4, 198.7, 38.8, 138.2};
double varNumber [10];

class Range
{
public:
	double mean();
	double subtract();
	double square();
	double total();
	double avg();

	double SumX();
	double SumY();
	double SumZ();
	double SumXY();
	double SumXX();
	double SumXZ();
	double NumAvg();
	double EstAvg();
	double ActAvg();
	double xy();
	double xx();
	double xz();
	double Slope();
	double Intercept();
	double Regression();

	double width(double x_high, double x_low);
	double function(double x_low, double width);
};

double Range::mean()
{
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += Numbers[i];
	}
	return sum/10.0;
}

double Range::subtract()
{
	double num = 0.0;
	for (int i = 0; i < 10; i++)
	{
		if (Numbers[i] < mean())
		{
			num = mean() - Numbers[i];
		}
		else
		{
			num = Numbers[i] - mean();
		}
		varNumber[i] = num;
		cout << varNumber[i] << endl;
	}
	return num;	//figure this part out for last random number
}

double Range::square()
{
	double num = 0.0;
	for (int i = 0; i < 10; i++)
	{
		num = varNumber[i] * varNumber[i];
		varNumber[i] = num;
		cout << setprecision(12) << varNumber[i] << endl;
	}
	return num; //figure this part out for last random number 
}

double Range::total()
{
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += varNumber[i];
	}
	return sum;
}

double Range::avg()
{
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += varNumber[i];
	}
	return sum/9;
}

double Range::SumX()
{
	double sumNum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumNum += Numbers[i];
	}
	return sumNum;
}

double Range::SumY()
{
	double sumEst = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumEst += estNumbers[i];
	}
	return sumEst;
}

double Range::SumZ()
{
	double sumAct = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumAct += actNumbers[i];
	}
	return sumAct;
}

double Range::SumXY()
{
	double xy = 0.0;
	double sumXY = 0.0;
	for (int i = 0; i < 10; i++)
	{
		xy = (Numbers[i] * estNumbers[i]);
		sumXY += xy;
	}
	return xy;
}

double Range::SumXZ()
{
	double xz = 0.0;
	double sumXZ = 0.0;
	for (int i = 0; i < 10; i++)
	{
		xz = (Numbers[i] * actNumbers[i]);
		sumXZ += xz;
	}
	return xz;
}

double Range::SumXX()
{
	double xx = 0.0;
	double sumXX = 0.0;
	for (int i = 0; i < 10; i++)
	{
		xx = (Numbers[i] * Numbers[i]);
		sumXX += xx;
	}
	return sumXX;
}

double Range::NumAvg()
{
	double sumNum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumNum += Numbers[i];
	}
	return sumNum/10;
}

double Range::EstAvg()
{
	double sumEst = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumEst += estNumbers[i];
	}
	return sumEst/10;
}

double Range::ActAvg()
{
	double sumAct = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumAct += actNumbers[i];
	}
	return sumAct/10;
}

double Range::xy()
{
	double xy = 0.0;
	double sumXY = 0.0;
	for (int i = 0; i < 10; i++)
	{
		xy = (Numbers[i] * estNumbers[i]);
		cout << xy << endl;
	}
	return xy;
}

double Range::xz()
{
	double xz = 0.0;
	double sumXZ = 0.0;
	for (int i = 0; i < 10; i++)
	{
		xz = (Numbers[i] * actNumbers[i]);
		cout << xz << endl;
	}
	return xz;
}

double Range::xx()
{
	double xx = 0.0;
	double sumXX = 0.0;
	for (int i = 0; i < 10; i++)
	{
		xx = (Numbers[i] * Numbers[i]);
		cout << xx << endl;
	}
	return xx;
}

double Range::width(double x_high, double x_low)
{
	double n = 10000.0;
	double w = 0.0;

	w = ((x_high - x_low) / n);
}

double Range::function(double x_low, double width)
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
Range r;

cout << r.mean() << endl << endl;
cout << r.subtract() << endl << endl;
cout << r.square() << endl << endl;
cout << r.total() << endl << endl;
cout << r.avg() << endl << endl;
cout << sqrt (r.avg()) << endl;

	double xk = 386.0;
	double alpha70 = .70;
	double alpha90 = .90;
	double t70 = 1.108;
	double t90 = 1.860;

	double range;
	for (int i = 1.0; i < 8.0; i++)
	{
		range = t70 * (alpha70, 8.0) * (sqrt (r.avg())) * (sqrt (1.0 +
(1.0/10.0) + ((((xk - r.avg()) * (xk - r.avg())) / ((i - r.avg()) * (i - r.avg()))))));
	}
	return range;

	for (int i = 1.0; i < 8.0; i++)
	{
		range = t90 * (alpha90, 8.0) * (sqrt (r.avg())) * (sqrt (1.0 +
(1.0/10.0) + ((((xk - r.avg()) * (xk - r.avg())) / ((i - r.avg()) * (i - r.avg()))))));
	}
	return range;
}
