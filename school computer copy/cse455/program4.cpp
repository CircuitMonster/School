#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

double Numbers [] = {130.0, 650.0, 99.0, 150.0, 128.0, 302.0, 95.0, 945.0, 368.0, 961.0};
double estNumbers [] = {163.0, 765.0, 141.0, 166.0, 137.0, 355.0, 136.0, 1206.0, 433.0, 1130.0};
double actNumbers [] = {186.0, 699.0, 132.0, 272.0, 291.0, 331.0, 199.0, 1890.0, 788.0, 1601.0};
double varNumber [10];


class Math
{
public:
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
};

double Math::SumX()
{
	double sumNum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumNum += Numbers[i];
	}
	return sumNum;
}

double Math::SumY()
{
	double sumEst = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumEst += estNumbers[i];
	}
	return sumEst;
}

double Math::SumZ()
{
	double sumAct = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumAct += actNumbers[i];
	}
	return sumAct;
}

double Math::SumXY()
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

double Math::SumXZ()
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

double Math::SumXX()
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

double Math::NumAvg()
{
	double sumNum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumNum += Numbers[i];
	}
	return sumNum/10;
}

double Math::EstAvg()
{
	double sumEst = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumEst += estNumbers[i];
	}
	return sumEst/10;
}

double Math::ActAvg()
{
	double sumAct = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sumAct += actNumbers[i];
	}
	return sumAct/10;
}

double Math::xy()
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

double Math::xz()
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

double Math::xx()
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

double Math::Slope()
{
	Math m;

	double slope = (((10 * m.SumXY()) - (m.SumX() * m.SumY())) / ((10 * m.SumXX()) - m.SumXX()));
}

double Math::Intercept()
{
	Math m;

	double incercept = ((m.SumY() - (m.Slope() * m.SumX())) / 10);
}

double Math::Regression()
{
	Math m;
	double x = 0.0;
	cout << "enter value for x: " << endl;
	cin >> x;
	double regression = (m.Intercept() + (m.Slope() + x));
}



int main()
{
Math math;

cout << math.SumX() << endl << endl;
cout << math.SumY() << endl << endl;
cout << math.SumZ() << endl << endl;
cout << math.SumXY() << endl << endl;
cout << math.SumXZ() << endl << endl;
cout << math.SumXX() << endl << endl;
cout << math.xy() << endl << endl;
cout << math.xz() << endl << endl;
cout << math.xx() << endl << endl;
cout << math.Slope() << endl << endl;
//cout << math.Intercept() << endl << endl;
//cout << math.Regression() << endl << endl;
}