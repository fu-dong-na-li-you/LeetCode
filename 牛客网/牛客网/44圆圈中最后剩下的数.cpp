#include "iostream"
using namespace std;
#include "vector"

//�˼ҵĴ��룬����
int LastRemaining_Solution2(int n, int m)
{
	if (n == 0) { return -1;}
	int s = 0;
	for (int i = 2; i <= n; i++)
	{
		s = (s + m) % i;
	}
	return s;
}


//�ҵĴ���
int LastRemaining_Solution(int n, int m)
{
	if (n == 0) { return -1;}
	vector<int> tmp(n);
	for (int i = 0; i < n; i++)
	{
		tmp[i] = i;
	}

	int len = n, index = -1, step = 0; //indexΪtmp������½Ǳ꣬ step��¼�ƶ��˶��ٸ�lenΪʣ������
	while (len != 0)  //ֱ�����һ�������֣���ֹͣ
	{
		index++;
		if (index == n ) { index = 0;}  //���½Ǳ�ָ������ĩβʱ���ٷ��ص���ǰ��
		if (tmp[index] == -1) { continue;}  //������-1ʱ��������λ���Ѿ����֣�ֱ������

		step++;
		if (step == m)    //����
		{
			tmp[index] = -1;   //��ʾ����
			len--;    //��Ч������һ��
			step = 0;  //���¼���
		}

	}
	return index;
}



void  main44()
{
	int res = LastRemaining_Solution(5, 3);
	cout << res << endl;

	system("pause");
}