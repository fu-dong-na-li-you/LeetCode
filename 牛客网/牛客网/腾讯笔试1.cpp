#include "iostream"
using namespace std;

int main_tengxun1()
{
	int n, m;
	cin >> n; cin >> m;
	if (n % (2*m) != 0) { return 0;}
	
	int num = n / (2 * m);  //表示一共有几组
	cout << num*m*m << endl;
	system("pause");
	return 0;
}
