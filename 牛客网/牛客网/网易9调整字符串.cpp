#include "iostream"
using namespace std;

int main_wangyi9()
{
	char str[50];
	gets_s(str, 50);

	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] != '\0' && str[i] != str[0])
		{
			count++;
		}
	}
	//cout << i << endl;
	cout << count << endl;
	system("pause");
	return 0;
}