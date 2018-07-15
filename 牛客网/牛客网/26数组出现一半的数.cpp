#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

int MoreThanHalfNum_Solution(vector<int> numbers) {
	int  len = numbers.size();
	if (len == 0) { return 0; }
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		num = count(numbers.begin(), numbers.end(), numbers[i]);
		if (num >(len / 2))
		{
			return numbers[i];
		}
	}
	return 0;
}

void main26()
{
	system("pause");
}