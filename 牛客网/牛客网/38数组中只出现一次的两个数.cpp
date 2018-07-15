#include "iostream"
using namespace std;
#include "vector"

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	if (data.size() < 2) { return; }
	int count_num = 0;
	vector<int>  tmp;
	for (int i = 0; i < data.size(); i++)
	{
		count_num = count(data.begin(), data.end(), data[i]);
		if (count_num == 1)
		{
			tmp.push_back(data[i]);
		}
	}
	*num1 = tmp[0];
	*num2 = tmp[1];
}
