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
		if (num <= vec[j]) //前两个数加起来不超过第三个数，则将前两个数相加
		{
			vec[0] = num;
			vec[1] = vec[j];
		}

		else //前两个数加起来超过第三个数，则将第三个数加入较小的数中
		{
			if (vec[0] <= vec[1]) { vec[0] = vec[0] + vec[j]; }
			
			else      {vec[1] = vec[1] + vec[j];}
		}
	}
	cout << max(vec[0], vec[1]);

	system("pause");
	return 0;
}