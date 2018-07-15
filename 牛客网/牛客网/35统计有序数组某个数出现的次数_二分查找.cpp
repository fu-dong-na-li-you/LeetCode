#include "iostream"
using namespace std;
#include "vector"

//����һ  ʱ�临�Ӷ�Ϊ n
int GetNumberOfK(vector<int> data, int k)
{
	return count(data.begin(), data.end(), k);
}

//������   ���ֲ��ң����Ӷ�Ϊlog(n)
int getUpper(vector<int> data, int k)    //�ҵ�k���ֵ����һ��
{
	int begin = 0, end = data.size() - 1;
	int mid = (begin + end) / 2;

	while (begin <= end)
	{
		if (data[mid] <= k)  //���С�ڵ��ڵĻ�����Ȼ����begin+1
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (begin + end) / 2;
	}
	return end;
}

int getLower(vector<int> data, int k)  //�ҵ�k���ֵĵ�һ��
{
	int begin = 0, end = data.size() - 1;
	int mid = (begin + end) / 2;

	while (begin <= end)
	{
		if (data[mid] < k)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (begin + end) / 2;
	}
	return begin;
}

int GetNumberOfK2(vector<int> data, int k)
{
	int upper = getUpper(data, k);
	int lower = getLower(data, k);
	return upper - lower + 1;
}

void main35()
{
	vector<int> data{ 1, 2, 3, 3, 3, 3, 4, 5 };
	int num = GetNumberOfK2(data, 3);
	cout << num << endl;
	system("pause");
}