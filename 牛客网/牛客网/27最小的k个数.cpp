#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> res;
	if (k > input.size()) { return res; }

	sort(input.begin(), input.end());
	for (int i = 0; i < k; i++)
	{
		res.push_back(input[i]);
	}

	return res;
}

void main27()
{
	system("pause");
}