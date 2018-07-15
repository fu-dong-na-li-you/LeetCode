#include "iostream"
using namespace std;
#include "vector"

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.size() != popV.size()) { return false;}
	if (popV.size() == 0) { return false; }
	vector<int> v{ -8562 };
	int index = -1;

	for (int i = 0; i < popV.size(); i++)
	{
		index++;
		while (v.back() != popV[i])  // 将pushV的值倒序输出，寻找和popV中相等的值
		{
			if (index < pushV.size())
			{
				v.push_back(pushV[index]); //如果不相等，则将值放入辅助的栈中
			}
			else
			{
				return false;
			}
		}
		v.pop_back();
	}
	return true;
}

void main20()
{
	system("pause");
}