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
			string sub = str.substr(index, i - index); //取出空格前面的子字符串
			tmp.push_back(sub);
			index = i + 1;
		}
	}
	tmp.push_back(str.substr(index, str.size()));  //取出最后一个没有空格的自字符串

	for (int j = tmp.size() - 1; j >= 0; j--)
	{
		if (j != 0)  { res = res + tmp[j] + ' '; }
		else { res = res + tmp[j]; }          //最后一个没有“ ”
	}
	return res;

}

