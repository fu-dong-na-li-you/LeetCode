#include "iostream"
using namespace std;
#include "string"

int main_zhaoshang()
{
	string A,B;
	//cin >> A; cin >> B;
	A = "bcbcbcbcbcb";
	B = "bcb";
	
	int ncount = 0;
	int pos;
	pos = A.find(B,0);
	while (pos != -1)
	{
		ncount++;
		pos = A.find(B, pos+strlen(B.c_str()));
	}
	cout << ncount << endl;

	system("pause");
	return 0;

}
