#include "iostream"
using namespace std;
#include "string"

int StrToInt(string str) {
	int len = str.size();
	if (len == 0) { return  0; }
	int res = 0;
	if (str[0] >= '0' && str[0] <= '9')   //�ַ����п�ͷû�з���
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')  { res = res + (str[i] - 48) *pow(10, len - 1 - i); }

			else  { return 0; }
		}
		return res;   //ֱ�ӷ�����ֵ
	}

	else   // �ַ������з���
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