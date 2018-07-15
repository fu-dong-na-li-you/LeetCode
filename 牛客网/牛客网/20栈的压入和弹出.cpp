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
		while (v.back() != popV[i])  // ��pushV��ֵ���������Ѱ�Һ�popV����ȵ�ֵ
		{
			if (index < pushV.size())
			{
				v.push_back(pushV[index]); //�������ȣ���ֵ���븨����ջ��
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