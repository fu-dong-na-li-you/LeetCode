#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int ans = INT_MAX;

bool ok(vector<int> &x, int dep)
{
	if (dep > 0 && x[dep - 1] == x[dep]) //两个使用的颜色一样
		return false;
	return true;
}

void dfs(int dep, int sum, vector<int> &x, int n, int k, vector<vector<int>>& costs)
{
	if (dep >= n)
	{
		if (sum < ans)
			ans = sum;
		return;
	}

	for (int i = 0; i < k; ++i)
	{
		x[dep] = i;  
		if (ok(x, dep))
		{
			dfs(dep + 1, sum + costs[dep][i], x, n, k, costs);
		}
		x[dep] = -1; //????
	}
}


/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int minCost(vector<vector<int>>& costs)
{
	int n = costs.size();
	if (n == 0)
		return 0;
	int m = costs[0].size();
	if (m == 0)
		return 0;
	vector<int> x(n, -1);  
	dfs(0, 0, x, n, m, costs);
	return ans;
}

int main_alibaba_1()
{
	int N, K;
	int cost;
	vector<vector<int> > costs;
	string s;
	istringstream is;

	getline(cin, s);
	is.str(s);
	is >> N >> K;
	for (int i = 0; i < N; i++)
	{
		vector<int> t;
		getline(cin, s);
		is.clear();
		is.str(s);
		for (int j = 0; j < K; j++) {
			is >> cost;
			t.push_back(cost);
		}
		costs.push_back(t);
	}
	cout << minCost(costs) << endl;
	return 0;
}

int main_alibaba_2()
{
	int n, k;
	int D[100][100];
	cin >> n >> k;//n个块，k个颜色  
	for (int i = 1; i <= n; i++)//输入价格  
	for (int j = 1; j <= k; j++)
		cin >> D[i][j];

	for (int i = n - 1; i >= 1; i--)  //从倒数第二行开始，计算当前值与下一行中不同列的元素的最小值  
	{
		for (int j = 1; j <= k; j++)  //遍历倒数第二行所用的所有颜色，找到所有颜色搭配下一行颜色的最小值
		{
			int min = 1000;
			for (int r = 1; r <= k; r++)  //遍历倒数第一行所用的所有颜色
			{
				if (r == j)
					continue;
				if (D[i][j] + D[i + 1][r] < min)
					min = D[i][j] + D[i + 1][r];
			}
			D[i][j] = min;
		}
	}//动态规划完毕  
	int min = 1000;
	for (int i = 1; i <= k; i++)//取出最小值  
	{
		if (D[1][i] < min)
			min = D[1][i];
	}
	cout << min;
	return 0;
}