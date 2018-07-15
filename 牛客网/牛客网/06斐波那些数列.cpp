#include "iostream"
using namespace std;

int Fibonacci(int n) {

	if (n < 2){ return n; }
	if (n == 2) { return 1; }
	int x;
	int a = 1;
	int b = 1;
	for (int i = 1; i < n - 1; i++)
	{
		x = a + b;
		a = b;
		b = x;
	}
	return  x;
}

void main06()
{
	system("pause");
}