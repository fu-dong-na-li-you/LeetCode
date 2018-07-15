#include "iostream"
using namespace std;
#include "vector"

bool   juge(vector<int> sequen, int left, int right)
{
	if (left == right) { return  true; }
	int temp = left;

	//最后一个元素为X，前一段（左子树）小于X，后一段（右子树）大于X
	while (temp < right && sequen[temp] < sequen[right])
	{
		temp++;  //找到左右子树的分界点
	}

	int  index = temp;
	while (index < right && sequen[index] >sequen[right])  //判断右子树是否符合条件
	{
		index++;
	}
	if (index < right) { return false; }

	if (temp == left || temp == right)    //考虑只有一边子树
	{
		return juge(sequen, left, right - 1);
	}
	else
	{
		return  (juge(sequen, left, temp - 1) && juge(sequen, temp, right - 1));
	}
}

bool VerifySquenceOfBST(vector<int> sequence) {
	int  len = sequence.size();
	if (len == 0) { return false;}

	return juge(sequence, 0, len - 1);
}