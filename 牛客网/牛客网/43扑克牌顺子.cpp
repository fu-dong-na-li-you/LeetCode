#include "iostream"
#include "vector"
using namespace std;

bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5) { return false;}
	int max = -1, min = 14;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 0) { continue; }   //如果是0，不做任何处理

		int num = count(numbers.begin(), numbers.end(), numbers[i]); //确保数组中没有任何重复的数
		if (num != 1) { return false; }

		if (numbers[i] > max) { max = numbers[i]; }
		if (numbers[i] < min)  { min = numbers[i]; }
	}
	if ((max - min) >= 5) { return false;}  //数组中没有重复的数，但是最大值最小值大于等于5
	
	return true;
}