#include "iostream"
using namespace std;
#include "vector"
#include "string"

string ReverseSentence(string str) {
	if (str.size() == 0) { return "";}
	vector<string> tmp;
	string  res;
	int index = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' '){
			string sub = str.substr(index, i - index); //ȡ���ո�ǰ������ַ���
			tmp.push_back(sub);
			index = i + 1;
		}
	}
	tmp.push_back(str.substr(index, str.size()));  //ȡ�����һ��û�пո�����ַ���

	for (int j = tmp.size() - 1; j >= 0; j--)
	{
		if (j != 0)  { res = res + tmp[j] + ' '; }
		else { res = res + tmp[j]; }          //���һ��û�С� ��
	}
	return res;

}

