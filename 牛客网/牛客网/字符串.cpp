/*
最长公共子序列（动态规划），最长公共子串（动态规划），
最长回文子串（动态规划，后缀数组），
最长重复子串（后缀数组），
最长不重复子串（hash, 动态规划，hash + 动态规划）。
*/
#include "iostream"
using namespace std;
#include "string"

void main()
{
	string str = "abcsdfasdfasdfdef";
	string a = str.erase(2, 3);  //str.erase(pos, len); 返回删除后的字符串
	cout << a << endl;
	
	string b = str.substr(2, 5); // str.substr(pos, len); 返回找到的子串
	cout << b << endl;
	
	char *B = "bcs";
	int pos = str.find(B, 3); // str.find("aasd",pos);
	                          //返回如果找了，返回子串的出现的第一个位置，没找打返回-1
	cout << pos << endl;                              

	system("pause");
	return;
}