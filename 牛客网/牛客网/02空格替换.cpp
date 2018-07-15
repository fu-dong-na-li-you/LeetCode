#include "iostream"
using namespace std;
#include "string"

void replaceSpace(char *str, int length)
{
	if (str == NULL)
		return;
	int CountOfBlanks = 0;
	int Originallength = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		Originallength++;
		if (str[i] == ' ')
			++CountOfBlanks;
	}
	int len = Originallength + 2 * CountOfBlanks;
	if (len + 1 > length)
		return;

	char*pStr1 = str + Originallength;// 指向原始数据的最尾部
	char*pStr2 = str + len;     //指向新数据的最尾部
	while (pStr1 < pStr2)
	{
		if (*pStr1 == ' ')
		{
			*pStr2-- = '0';
			*pStr2-- = '2';
			*pStr2-- = '%';
		}
		else
		{
			*pStr2-- = *pStr1;
		}
		--pStr1;
	}
	printf("%s", pStr2);
}


void  main02()
{
	char *a = new char[20];
	char *b = "We Are Happy";
	for (int i = 0; b[i] != '\0'; i++)
	{
		a[i] = b[i];
	}
	printf("%s", a);
	
	//replaceSpace(a, 20);
	system("pause");
}