#include "iostream"
using namespace std;
#include "string"


string LeftRotateString(string str, int n) {
	int len = str.size();
	if (len == 0) { return ""; }
	n = n%len;        //��n����len�ĳ���ʱ�򣬿���ȡ��

	//string *p = strstr��str1��str2�����ص��Ǵ�str1�е�str2λ���𣬷���str1��ָ��λ��
	string tmp = str.substr(0, n);  //����һ����Χ�ڵ����ַ��������ص����ַ��� ���ַ���0��ʼ�����ҳ���Ϊn���ַ���

	str.erase(0, n);     //ɾ��һ����Χ�ڵ��ַ���������������һ��Ԫ�ص�λ�� str.erase(str.begin(), str.end())
	str = str + tmp;    

	return str;
}