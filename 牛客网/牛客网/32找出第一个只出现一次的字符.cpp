#include "iostream"
using namespace std;
#include "string"

int FirstNotRepeatingChar(string str)
{
	if (str.size() == 0) { return -1; }
	int num = 0;
	for (int i = 0; i < str.size(); i++)
	{
		num = count(str.begin(), str.end(), str[i]);
		if (num == 1)
		{
			return i;
		}
	}
	return -1;
}

void  main32()
{
	system("pause");
}