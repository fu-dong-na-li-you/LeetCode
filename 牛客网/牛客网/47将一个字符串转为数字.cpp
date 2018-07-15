#include "iostream"
using namespace std;
#include "string"

int StrToInt(string str) {
	int len = str.size();
	if (len == 0) { return  0; }
	int res = 0;
	if (str[0] >= '0' && str[0] <= '9')   //字符串中开头没有符号
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')  { res = res + (str[i] - 48) *pow(10, len - 1 - i); }

			else  { return 0; }
		}
		return res;   //直接返回数值
	}

	else   // 字符串中有符号
	{
		for (int i = len - 1; i > 0; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')  { res = res + (str[i] - 48) *pow(10, len - 1 - i); }

			else   { return 0; }
		}
		if (str[0] == '+') { return res; }
		if (str[0] == '-') { return -res; }
	}
	return 0;
}