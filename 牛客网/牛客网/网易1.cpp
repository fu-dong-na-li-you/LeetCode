#include "iostream"
using namespace std;
#include "string"
#include "algorithm"


string magicMachine(int n)
{	
	string str;
	if (n <= 0) { return ""; }
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			str = str + "2";
			n = (n - 2) / 2;
		}
		else
		{
			str = str + "1";
			n = (n - 1) / 2;
		}
	}
	reverse(str.begin(), str.end());
	 return str;
	 
}

int main_wangyi1()
{
	int n;
	cin >> n;
	cout << magicMachine(n) << endl;
	system("pause");
	return 0;
}