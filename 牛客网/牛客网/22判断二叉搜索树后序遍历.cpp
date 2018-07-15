#include "iostream"
using namespace std;
#include "vector"

bool   juge(vector<int> sequen, int left, int right)
{
	if (left == right) { return  true; }
	int temp = left;

	//���һ��Ԫ��ΪX��ǰһ�Σ���������С��X����һ�Σ�������������X
	while (temp < right && sequen[temp] < sequen[right])
	{
		temp++;  //�ҵ����������ķֽ��
	}

	int  index = temp;
	while (index < right && sequen[index] >sequen[right])  //�ж��������Ƿ��������
	{
		index++;
	}
	if (index < right) { return false; }

	if (temp == left || temp == right)    //����ֻ��һ������
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