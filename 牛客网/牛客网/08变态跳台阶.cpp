#include "iostream"
using namespace std;

int jumpFloorII(int number) {   //ÿ��̨�׶������벻������������������һ��̨�ף���
	                            //���һ��̨�ױ����������Թ���2^(n-1)�����
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