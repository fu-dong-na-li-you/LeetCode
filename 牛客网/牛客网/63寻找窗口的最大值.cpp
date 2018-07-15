#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int>  res;
	if (size == 0) { return res;}
	if (size > num.size()) { return res; }
	int tmp;
	int len = num.size() - size + 1;
	for (int i = 0; i < len; i++)
	{
		tmp = *max_element(num.begin()+i, num.begin()+size+i);  //搜索时，不包含末尾一个数
		res.push_back(tmp);
	}

	return res;
}

void  main63()
{
	vector<int>  v{2, 3, 4, 2, 6, 2, 5, 1};

	vector<int> x = maxInWindows(v, 3);
	for (int i = 0; i < x.size(); i++)
	{
		cout << x[i] << "   ";
	}

	system("pause");
}