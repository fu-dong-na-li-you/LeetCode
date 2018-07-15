#include "iostream"
using namespace std;

double Power(double base, int exponent) {

	double  result = 1;
	if (exponent == 0) { return result; }
	for (int i = 0; i < exponent; i++)
	{
		result = result *base;
	}

	for (int i = exponent; i < 0; i++)
	{
		result = result / base;
	}

	return  result;

}

void  main11()
{
	system("pause");
}