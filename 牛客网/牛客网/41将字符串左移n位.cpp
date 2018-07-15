#include "iostream"
using namespace std;
#include "string"


string LeftRotateString(string str, int n) {
	int len = str.size();
	if (len == 0) { return ""; }
	n = n%len;        //当n大于len的长度时候，可以取余

	//string *p = strstr（str1，str2）返回的是从str1中的str2位置起，返回str1的指针位置
	string tmp = str.substr(0, n);  //返回一个范围内的子字符串，返回的是字符串 从字符串0开始，查找长度为n的字符串

	str.erase(0, n);     //删除一个范围内的字符串，返回容器下一个元素的位置 str.erase(str.begin(), str.end())
	str = str + tmp;    

	return str;
}