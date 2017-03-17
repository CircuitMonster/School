#include "Number.h"

Number::Number(int n) { this->n = n; }

bool Number::isPrime()
{
	for (int k = 2; k < n; ++k)
	{
		if (n % k == 0)
		{
			return false;
		}
	}
	return true;
}

bool Number::isDivisibleBy(int k)
{
	if (n % k == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
