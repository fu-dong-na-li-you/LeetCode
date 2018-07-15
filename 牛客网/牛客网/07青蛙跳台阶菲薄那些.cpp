#include "iostream"
using namespace std;

int jumpFloor(int number) {
	if (number == 1){ return 1; }
	if (number == 2){ return 2; }

	return  jumpFloor(number - 1) + jumpFloor(number - 2);

}


void main07()
{
	system("pause");
}