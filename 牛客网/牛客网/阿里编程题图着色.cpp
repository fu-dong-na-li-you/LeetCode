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
	if (dep > 0 && x[dep - 1] == x[dep]) //����ʹ�õ���ɫһ��
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


/** ������������������ʵ����ĿҪ��Ĺ��� **/
/** ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^  **/
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
	cin >> n >> k;//n���飬k����ɫ  
	for (int i = 1; i <= n; i++)//����۸�  
	for (int j = 1; j <= k; j++)
		cin >> D[i][j];

	for (int i = n - 1; i >= 1; i--)  //�ӵ����ڶ��п�ʼ�����㵱ǰֵ����һ���в�ͬ�е�Ԫ�ص���Сֵ  
	{
		for (int j = 1; j <= k; j++)  //���������ڶ������õ�������ɫ���ҵ�������ɫ������һ����ɫ����Сֵ
		{
			int min = 1000;
			for (int r = 1; r <= k; r++)  //����������һ�����õ�������ɫ
			{
				if (r == j)
					continue;
				if (D[i][j] + D[i + 1][r] < min)
					min = D[i][j] + D[i + 1][r];
			}
			D[i][j] = min;
		}
	}//��̬�滮���  
	int min = 1000;
	for (int i = 1; i <= k; i++)//ȡ����Сֵ  
	{
		if (D[1][i] < min)
			min = D[1][i];
	}
	cout << min;
	return 0;
}