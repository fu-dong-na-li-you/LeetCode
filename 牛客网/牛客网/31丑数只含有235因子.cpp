#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int GetUglyNumber_Solution(int index) {
	if (index < 7) { return index; }
	vector<int>  res(index);   //���vector����һ��index������

	res[0] = 1;
	int  t2 = 0, t3 = 0, t5 = 0, i;
	for (i = 1; i < index; i++)
	{
		res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));  //��С�����ֱ��2�� 3,  5ƥ�䣬ȡ������С�ĳ���
		if (res[i] == res[t2] * 2)  t2++;
		if (res[i] == res[t3] * 3)  t3++;
		if (res[i] == res[t5] * 5)  t5++;
	}

	return res[index - 1];
}


void main31()
{
	system("pause");
}