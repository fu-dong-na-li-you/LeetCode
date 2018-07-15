#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() == 0) { return 0; }
	int cursum = array[0];  //��ʼֵΪ����ĵ�һ��Ԫ��
	int maxsum = array[0]; // ������ʼֵΪ���ֵ

	for (int i = 1; i < array.size(); i++)
	{
		cursum += array[i];
		if (cursum < array[i])  //�����������֤���������֮ǰ���ܺ���С����ģ������ս��û�й��ף�������
		{
			cursum = array[i];
		}

		if (cursum > maxsum) //�����ǰ�ܺʹ������ֵ����������ֵ
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