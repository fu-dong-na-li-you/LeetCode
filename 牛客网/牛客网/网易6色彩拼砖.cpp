#include "iostream"
using namespace std;
#include "string"
#include "algorithm"

int main_wangyi6()
{
	string str;
	cin >> str;

	sort(str.begin(), str.end());
	int num = 1;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i - 1] != str[i])
			num++;
	}
	if (num >2) { cout << 0 << endl; }
	else { cout << num << endl; }

	system("pause");
	return 0;
}