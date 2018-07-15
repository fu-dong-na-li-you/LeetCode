#include "iostream"
using  namespace std;
#include "vector"


vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int>  res;
	if (array.size() < 2) { return res; }
	int low = 0, high = array.size() - 1, CurSum = 0;
	while (low < high)
	{
		CurSum = array[low] + array[high];
		if (CurSum > sum)  { high--; }

		else if (CurSum < sum)    { low++; }

		else
		{
			res.push_back(array[low]);
			res.push_back(array[high]);
			break;
		}
	}
	return res;
}