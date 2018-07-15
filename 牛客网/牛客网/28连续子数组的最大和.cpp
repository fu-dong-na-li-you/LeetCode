#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() == 0) { return 0; }
	int cursum = array[0];  //起始值为数组的第一个元素
	int maxsum = array[0]; // 假设起始值为最大值

	for (int i = 1; i < array.size(); i++)
	{
		cursum += array[i];
		if (cursum < array[i])  //如果成立，则证明在这个数之前的总和是小于零的，对最终结果没有贡献，舍弃掉
		{
			cursum = array[i];
		}

		if (cursum > maxsum) //如果当前总和大于最大值，则更新最大值
		{
			maxsum = cursum;
		}
	}
	return maxsum;
}

void main28()
{
	system("pause");
}