#include "iostream"
using namespace std;
#include "vector"

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> res;
	int low = 1, high = 2, curSum = 1;
	while (low < high)
	{
		curSum = curSum + high;   //CurSum累积值会随着high的增加而增加，最终会超过sum
		high++;
		while (curSum > sum)
		{
			curSum = curSum - low;  //在CurSum超过sum后会逐渐减去low，最终会低于sum
			low++;
		}

		if (curSum == sum && low != high - 1)  //最终找到和sum相等的值, 同时low和high不能为同一个值
		{
			vector<int> tmp;
			for (int i = low; i < high; i++)
			{
				tmp.push_back(i);
			}
			res.push_back(tmp);
		}
		return res;
	}

}