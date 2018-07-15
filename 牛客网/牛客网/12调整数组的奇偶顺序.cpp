#include "iostream"
using namespace std;
#include "vector"

void reOrderArray(vector<int> &array) {
	vector<int> result;
	int num = array.size();
	for (int i = 0; i < num; i++)
	{
		if (array[i] % 2 == 1)
			result.push_back(array[i]);
	}
	for (int i = 0; i < num; i++)
	{
		if (array[i] % 2 == 0)
			result.push_back(array[i]);
	}
	array = result;
}

void main12()
{
	system("pause");
}