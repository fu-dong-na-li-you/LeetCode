#include "iostream"
using namespace std;
#include "algorithm"
#include "vector"

int minNumberInRotateArray(vector<int> rotateArray) {
	sort(rotateArray.begin(), rotateArray.end());

	return rotateArray[0];

}

void  main05()
{
	system("pause");
}
