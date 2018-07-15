#include "iostream"
using namespace std;
#include "vector"

int num_rev(int n)
{
	if (n == 0) { return 0;}
	vector<int> v;
	while (n)
	{
		v.push_back(n % 10);
		n = n / 10;
	}
	int len = v.size(), res = 0;
	for (int i = 0; i < len; i++)
	{
		int tmp = v[i] + v[len - 1 - i];
		res = res * 10 + tmp;     
	}

	return res;
}

int main_wangyi2()
{
	int n;
	cin >> n;
	cout<<num_rev(n);
	system("pause");
	return 0;
}