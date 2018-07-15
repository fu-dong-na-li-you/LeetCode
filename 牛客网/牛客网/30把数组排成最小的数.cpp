#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "string"

static  bool cmp(int a, int b)
{
	string  A = to_string(a) + to_string(b);  //字符串进行比较
	string  B = to_string(b) + to_string(a);
	return A < B;   //返回false则交换，返回true则不交换
}

string PrintMinNumber(vector<int> numbers) {
	if (numbers.size() == 0) { return "";}
	sort(numbers.begin(), numbers.end(), cmp); //从小到大排序
	string  res;
	for (int i = 0; i < numbers.size(); i++)
	{
		res = res + to_string(numbers[i]);
	}

	return res;
}

void main30()
{

	vector<int> v{ 1, 8, 7, 5 };
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	system("pause");
}