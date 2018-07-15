#include <iostream>
using namespace std;


int GetMaxValue(int n, int m, int *w, int *v, int *c)
{
	{
		int row = n + 1;
		int col = m + 1;

		int i, j;    //循环变量:前i个物品能够装入载重量为j的背包中

		//value[i][j]表示前i个物品能装入载重量为j的背包中物品的最大价值
		int **value = new int*[row];
		for (i = 0; i < row; i++)
			value[i] = new int[col];

		//初始化第0行
		for (j = 0; j < col; j++)
			value[0][j] = 0;

		//初始化第0列
		for (i = 0; i < row; i++)
			value[i][0] = 0;

		//计算
		for (i = 1; i < row; i++)
		{
			for (j = 1; j<col; j++)
			{
				//w[i]>j,第i个物品不装入背包
				value[i][j] = value[i - 1][j];
				//w[i]<=j,且第i个物品装入背包后的价值>value[i-1][j],则记录当前最大价值
				int temp = value[i - 1][j - w[i]] + v[i];
				if (w[i] <= j && temp>value[i][j])
					value[i][j] = temp;
			}
		}

		//逆推求装入的物品
		j = m;
		for (i = row - 1; i > 0; i--)
		{
			if (value[i][j] > value[i - 1][j])
			{
				c[i] = 1;
				j -= w[i];
			}
		}

		//记录最大价值
		int nMaxVlaue = value[row - 1][col - 1];

		//释放该二维数组
		for (i = 0; i < row; i++)
		{
			delete[col]value[i];
			value[i] = NULL;
		}
		delete[] value;
		value = NULL;

		return nMaxVlaue;
	}
}

void test1()
{
	int n, C;
	while (cin >> n >> C)  //n为物品个数，C为背包承受重量
	{
		int *W = new int[n];
		int *V = new int[n];
		int *res = new int[n];
		for (int i = 0; i < n; i++)
		{
			res[i] = 0;
		}
		int w = 0, v = 0, i = 0;
		while (i < n)
		{
			cin >> w >> v;
			W[i] = w;
			V[i] = v;
			i++;
		}
		int value = GetMaxValue( n, C,W, V, res);
		cout << value << endl;
		for (int i = 0; i < n; i++)
			cout << res[i] << " ";
		cout << endl;
		delete W;
		delete V;
		delete res;
	}
}

int main_packect()
{
	test1();
	return 0;
}