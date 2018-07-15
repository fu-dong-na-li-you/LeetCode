#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int mainwangyi7()
{
	int n;
	cin >> n;
	if (n == 2)
	{
		cout << "Possible" << endl;
		return 0;
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v[i] = num;
	}
	sort(v.begin(), v.end());

	for (int j = 1; j < v.size()-1; j++)
	{
		if (v[j] - v[j - 1] != v[j + 1] - v[j])
		{
			
			cout << "Impossible" << endl;
			return 0;
		}
	}

	cout << "Possible" << endl;
	system("pause");
	return 0;
}