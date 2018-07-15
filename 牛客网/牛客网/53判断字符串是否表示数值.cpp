#include "iostream"
using namespace std;
#include "string"

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

void main53()
{
	char s[] = "12e";
	bool bb = isNumeric(s);
	if (bb)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "��" << endl;
	}

	system("pause");
}