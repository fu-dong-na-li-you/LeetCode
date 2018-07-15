#include "iostream"
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	if (n < 1) { return 0; }
	int countNum = 0;  //记录1出现的次数
	int num = 0;
	int tmp;  //临时变量的数值
	for (int i = 1; i <= n; ++i)
	{
		tmp = i;
		while (tmp)
		{
			num = tmp % 10;
			if (num == 1)  { countNum++; }
			tmp = tmp / 10;
		}
	}
	return countNum;
}

void main29()
{
	system("pause");
}