#include "iostream"
using namespace std;

bool match(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0') { return true; }

//��������if (*str != '\0' && *pattern == '\0')�жϣ���ΪstrΪ��ʱ�� pattern��Ϊ�գ��п��ܻ�ƥ��ɹ���str='\0', pattern ='a*a*'
	if (*str != '\0' && *pattern == '\0') { return false; }  

	//��һ���ַ���Ϊ��*��
	if (*(pattern + 1) != '*')
	{
		if (*pattern == *str || (*str != '\0'&& *pattern == '.')) 
			return match(str + 1, pattern + 1);
		else
			return false;
	}
	else   //��һ���ַ�Ϊ'*'
	{
		if (*pattern == *str || (*str != '\0' && *pattern == '.'))
			return match(str, pattern + 2) || match(str + 1, pattern);
    //match(str, pattern + 2) '*'����0�Ρ� match(str + 1, pattern) ��*������1�λ���
		else
			return match(str, pattern + 2); //�����ǰ�ַ�����ȣ���*����0�Ρ�
	}

	return true;
}

void main52()
{
	char s[] = "aaa";
	char p[] = "ab*a";

	bool ss = match(s, p);
	if (ss)
		cout << "��" << endl;
	else
		cout << "��" << endl;

	system("pause");
}
