#include "iostream"
using namespace std;

int main_wangyi5()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)  //输入多少行
	{
		int j;
		cin >> j;   //一行多少个数
		int count4 = 0, count1 = 0;
		for (int k = 0; k < j; k++)
		{
			int num;
			cin >> num;
			if (num % 4 == 0) { count4++; }  //能被4整除的数
			else if (num % 2 != 0) { count1++; } //奇数
		}
		if (count4 >= count1 || count4 >= count1 - 1 && (count4 + count1) == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	system("pause");
	return 0;
}