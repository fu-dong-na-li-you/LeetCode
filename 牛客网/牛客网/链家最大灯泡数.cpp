#include <iostream>
using namespace std;

int main_lianjia()
{
	int n;
	cin >> n; //有多少组
	int a[1000] = { 0 };  //可以控制的灯泡序号
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;  //一组灯泡可以控制的灯泡数
		
		for (int j = 0; j < num; j++)
		{
			int seq; cin >> seq;
			a[seq - 1] = 1;  //能够控制就设置为1
		}

	}
	int  count = 0;
	for (int k = 0; k < 1000; k++)
	{
		count += a[k];
	}
	
	cout << count << endl; 

	system("pause");
	return 0;
}