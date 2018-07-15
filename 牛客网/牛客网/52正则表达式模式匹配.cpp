#include "iostream"
using namespace std;

bool match(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0') { return true; }

//不能做当if (*str != '\0' && *pattern == '\0')判断，因为str为空时， pattern不为空，有可能会匹配成功的str='\0', pattern ='a*a*'
	if (*str != '\0' && *pattern == '\0') { return false; }  

	//下一个字符不为‘*’
	if (*(pattern + 1) != '*')
	{
		if (*pattern == *str || (*str != '\0'&& *pattern == '.')) 
			return match(str + 1, pattern + 1);
		else
			return false;
	}
	else   //下一个字符为'*'
	{
		if (*pattern == *str || (*str != '\0' && *pattern == '.'))
			return match(str, pattern + 2) || match(str + 1, pattern);
    //match(str, pattern + 2) '*'代表0次。 match(str + 1, pattern) ‘*’代表1次或多次
		else
			return match(str, pattern + 2); //如果当前字符不相等，则‘*代表0次’
	}

	return true;
}

void main52()
{
	char s[] = "aaa";
	char p[] = "ab*a";

	bool ss = match(s, p);
	if (ss)
		cout << "是" << endl;
	else
		cout << "否" << endl;

	system("pause");
}
