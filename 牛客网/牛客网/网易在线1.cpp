#include "iostream"
using namespace std;
#include "vector"

int main_online1()
{
	int num1, num2;
	cin >> num1;
	cin >> num2;

	vector<int>  vec;
	for (int i = num1; i <= num2; i++)
	{
		int tmp = 0; 
		for (int j = 1; j <= i; j++)   //iÎªÍ·¶ËÖµ
		{
			tmp = tmp*10 + j;
		}
		vec.push_back(tmp);
	}
	
	int count = 0;
	for (int k = 0; k < vec.size(); k++)
	{
		int aaa = vec[k] % 3;
		if (aaa == 0)
		{
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}