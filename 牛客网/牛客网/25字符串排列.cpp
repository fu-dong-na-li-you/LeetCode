#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "string"

//���û��ݷ����������
void  swapString(string  str, vector<string> &res, int index)
{
	if (index == str.size() - 1)  { res.push_back(str); } //�ڱ������ַ�����βʱ�����ַ���ѹջ

	for (int i = index; i < str.size(); i++)
	{
		if (i != index && str[i] == str[index])  //����ڲ�ͬ��λ�ó�����ͬ����ĸ���򲻽���, ����str = "aa"
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