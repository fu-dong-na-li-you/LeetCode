#include "iostream"
using namespace std;

bool isNumeric(char* string)
{
	if (string == NULL)
		return false;
	if (*string == '+' || *string == '-')
		string++;
	if (*string == '\0')
		return false;
	int dot = 0, num = 0, nume = 0;//�ֱ��������С���㡢�������ֺ�eָ���Ƿ����
	while (*string != '\0'){
		if (*string >= '0'&&*string <= '9')
		{
			string++;
			num = 1;
		}
		else if (*string == '.'){
			if (dot > 0 || nume > 0)
				return false;
			string++;
			dot = 1;
		}
		else if (*string == 'e' || *string == 'E')
		{
			if (num == 0 || nume > 0)
				return false;
			string++;
			nume++;
			if (*string == '+' || *string == '-')
				string++;
			if (*string == '\0')
				return false;
		}
		else
			return false;
	}
	return true;
}