#include "iostream"
using namespace std;
const int maxm = 2001, maxn = 101;
int m, n;
int w[maxn];
int f[maxm];
int main_wangyionline2()
{
	
	cin>>n;
	cin >> m;//����Ʒ����n�ͱ�������m
	for (int i = 1; i <= n; i++)
		cin>>w[i];     //ÿ����Ʒ�����

	int  count = 0;
	for (int i = 1; i <= n; i++)             //��f(v)��ʾ����������v���������ֵ
	{ 
		if (w[i] <m)
		{
			count++;
			m = m - w[i];
		}
	}
	int num = 1;
	for (int j = 0; j < count; j++)
	{
		num = num * 2;
	}

	cout <<num  << endl;
	return 0;
}