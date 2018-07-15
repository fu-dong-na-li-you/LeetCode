#include "iostream"
using namespace std;
#include "string"

void main_test()
{
	string str = "abcsdfasdfasdfdef";
	string a = str.erase(2,3);
	cout << a << endl;
	string b = str.substr(2, 5);
	cout << b << endl;
	string B = "bcs";
	int pos = str.find(B,3);
	cout << pos << endl;

	system("pause");
	return;
}