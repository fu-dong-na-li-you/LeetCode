#include <iostream>
using namespace std;

int main_lianjia()
{
	int n;
	cin >> n; //�ж�����
	int a[1000] = { 0 };  //���Կ��Ƶĵ������
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;  //һ����ݿ��Կ��Ƶĵ�����
		
		for (int j = 0; j < num; j++)
		{
			int seq; cin >> seq;
			a[seq - 1] = 1;  //�ܹ����ƾ�����Ϊ1
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