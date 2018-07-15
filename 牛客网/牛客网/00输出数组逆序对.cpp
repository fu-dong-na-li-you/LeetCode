#include "iostream"
#include "vector"
using namespace std;

long InversePairsCore(vector<int> &data, vector<int> &copy, long start, long end){
	if (start == end)  // copy: 辅助数组
	{
		return 0;  // 递归终止条件
	}

	long length = (end - start) / 2;
	long left = InversePairsCore(copy, data, start, start + length); // 递归，归并排序，并计算本次逆序对数
	long right = InversePairsCore(copy, data, start + length + 1, end);
	long crossCount = 0;       // 记录交叉的逆序对数
	long i = start + length, j = end, temp = end;  //i：前半部分的下标，j：后半部分的下标，temp：辅助数组的下标

	while (i >= start && j >= start + length + 1) {   // 存在交叉的逆序对，先统计一下，然后依次将较大值放进辅助数组
		if (data[i] > data[j]) {
			copy[temp--] = data[i--];
			crossCount += j - start - length;
		}
		else {
			copy[temp--] = data[j--];   // 不存在交叉的逆序对，依次将较大值放进辅助数组
		}
	}
	while (i >= start) {
		copy[temp--] = data[i--];
	}
	while (j >= start + length + 1) {
		copy[temp--] = data[j--];
	}
	return (left + right + crossCount) % 1000000007; //数值过大时求余, 防止溢出
}

int InversePairs(vector<int> &data) {
	if (data.size() == 0) return 0;
	else if (data.size() == 1) return 1;
	else {
		vector<int> copy(data);
		return InversePairsCore(copy, data, 0, data.size() - 1);
	}
}