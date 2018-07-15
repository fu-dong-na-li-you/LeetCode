#include "iostream"
using namespace std;
#include "vector"

bool Find(int target, vector<vector<int> > array) {
	for (int i = 0; i < array.size(); i++)
	{
		int low = 0;
		int high = array[i].size() - 1;
		int mid = (low + high) / 2;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (target > array[i][mid])
			{
				low = mid + 1;
			}
			else if (target < array[i][mid])
			{
				high = mid - 1;
			}
			else
				return true;
		}
	}
	return false;
}

void main01()
{
	vector<int> v1{1, 2, 3, 4};
	vector<int> v2{3, 4, 5, 6};
	vector<int> v3{5, 6, 7, 8};
	vector<int> v4{7, 8, 9, 10};
	vector<vector<int>>  v{ v1, v2, v3, v4 };

	bool a = Find(7, v);
	if (a)
	{
		cout << "ÊÇ" << endl;
	}
	else
	{
		cout << "·ñ" << endl;
	}

	system("pause");
}