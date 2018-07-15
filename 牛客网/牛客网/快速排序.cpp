#include "iostream"
using namespace std;
#include "algorithm"

int partSort(int *arry, int low, int high)   //确定数组第一个元素的位置
{
	int key = arry[low];  //每次对数组的第一个元素进行合理的安排
	while (low<high)
	{
		while (low < high && arry[high] >= key)
		{ 
			--high;
		}
		swap(arry[low], arry[high]);
		while (low < high && arry[low] <= key)
		{
			++low;
		}
		swap(arry[low], arry[high]);
	}

	return low;
}

void  quickSort(int *arry, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partSort(arry, low, high);

		quickSort(arry, low, pivot - 1);
		quickSort(arry, pivot + 1, high);
	}

}

void main_test5()
{
	int array[] = { 5, 1, 9, 3, 7, 4, 8, 6, 2 };
	quickSort(array, 0, 8);
	for (int i = 0; i < 8; i++)
	{
		cout << array[i] << "  ";
	}

	system("pause");
}