#include "iostream"
using namespace std;

int rectCover(int number) {
	if (number < 1) { return 0; }
	if (number == 1) { return 1; }
	if (number == 2){ return 2; }

	return  rectCover(number - 1) + rectCover(number - 2);

}

void  main09()
{

	system("pause");
}