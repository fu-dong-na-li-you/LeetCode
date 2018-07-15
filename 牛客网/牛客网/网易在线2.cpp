#include "iostream"
using namespace std;
const int maxm = 2001, maxn = 101;
int m, n;
int w[maxn];
int f[maxm];
int main_wangyionline2()
{
	
	cin>>n;
	cin >> m;//和物品数量n和背包容量m
	for (int i = 1; i <= n; i++)
		cin>>w[i];     //每个物品的体积

	int  count = 0;
	for (int i = 1; i <= n; i++)             //设f(v)表示重量不超过v公斤的最大价值
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