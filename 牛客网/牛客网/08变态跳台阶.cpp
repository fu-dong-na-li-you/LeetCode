#include "iostream"
using namespace std;

int jumpFloorII(int number) {   //每个台阶都有跳与不跳两种情况（除了最后一个台阶），
	                            //最后一个台阶必须跳。所以共用2^(n-1)中情况
	int sum = 1;
	for (int i = 1; i < number; i++)
	{
		sum = sum * 2;

	}
	return sum;
}

void main08()
{
	system("pause");
}