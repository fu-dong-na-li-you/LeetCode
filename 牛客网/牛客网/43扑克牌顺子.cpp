#include "iostream"
#include "vector"
using namespace std;

bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5) { return false;}
	int max = -1, min = 14;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 0) { continue; }   //�����0�������κδ���

		int num = count(numbers.begin(), numbers.end(), numbers[i]); //ȷ��������û���κ��ظ�����
		if (num != 1) { return false; }

		if (numbers[i] > max) { max = numbers[i]; }
		if (numbers[i] < min)  { min = numbers[i]; }
	}
	if ((max - min) >= 5) { return false;}  //������û���ظ��������������ֵ��Сֵ���ڵ���5
	
	return true;
}