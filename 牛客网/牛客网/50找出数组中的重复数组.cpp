#include "iostream"
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == NULL || length == 0) { return false; }
	
	int tmp = -1;
	for (int i = 0; i < length; i++)
	{
		tmp = numbers[i];   //��¼������ÿһ����ֵ�����бȽ�
		for (int j = i + 1; j < length; j++)
		{
			if (tmp == numbers[j])
			{
				*duplication = tmp;
				return true;
			}
		}
	}
	return false;

}

void  main50()
{
	int a[] = { 2, 3, 1, 0, 2, 5, 3 };
	int len = sizeof(a) / sizeof(a[0]);
	int dup = -1;

	bool ss = duplicate(a, len, &dup);
	if (ss)
		cout << "��" << endl;
	else
	{
		cout << "��" << endl;
	}
	cout << dup << endl;
	system("pause");
}