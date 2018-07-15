#include "iostream"
using namespace std;
#include "string"

float time_split(string str)
{
	int len = str.size();
	if (len == 0) { return 0;}
	int num = 1;
	for (int i = 1; i < len; i++)
	{
		if (str[i - 1] != str[i])
		{
			++num;
		}
	}
	return float(len) / float(num);
}

int main_wangyi3()
{
	string str;
	cin >> str;
	printf("%.2f", time_split(str));
	system("pause");
	return 0;
}