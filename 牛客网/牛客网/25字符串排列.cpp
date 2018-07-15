#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "string"

//采用回溯法，解决问题
void  swapString(string  str, vector<string> &res, int index)
{
	if (index == str.size() - 1)  { res.push_back(str); } //在遍历到字符串结尾时，将字符串压栈

	for (int i = index; i < str.size(); i++)
	{
		if (i != index && str[i] == str[index])  //如果在不同的位置出现相同的字母，则不交换, 例如str = "aa"
		{
			continue;
		}
		swap(str[i], str[index]);
		swapString(str, res, index + 1);
		swap(str[i], str[index]);
	}

}

vector<string> Permutation(string str) {
	vector<string> res;
	if (str.length() == 0) { return res; }

	swapString(str, res, 0);
	sort(res.begin(), res.end());

	return res;
}


void main25()
{
	string str = "abc";
	vector<string> v = Permutation(str);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	system("pause");
}