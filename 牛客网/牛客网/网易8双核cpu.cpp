#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int  main_wangyi8()
{
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	if (n == 0) { cout<<0;}
	if (n == 1) { cout<< vec[0]<<endl; }

	for (int j = 2; j < n; j++)
	{
		int num = vec[0] + vec[1];
		if (num <= vec[j]) //ǰ������������������������������ǰ���������
		{
			vec[0] = num;
			vec[1] = vec[j];
		}

		else //ǰ���������������������������򽫵������������С������
		{
			if (vec[0] <= vec[1]) { vec[0] = vec[0] + vec[j]; }
			
			else      {vec[1] = vec[1] + vec[j];}
		}
	}
	cout << max(vec[0], vec[1]);

	system("pause");
	return 0;
}