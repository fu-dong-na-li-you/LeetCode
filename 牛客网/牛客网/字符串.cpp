/*
����������У���̬�滮����������Ӵ�����̬�滮����
������Ӵ�����̬�滮����׺���飩��
��ظ��Ӵ�����׺���飩��
����ظ��Ӵ���hash, ��̬�滮��hash + ��̬�滮����
*/
#include "iostream"
using namespace std;
#include "string"

void main()
{
	string str = "abcsdfasdfasdfdef";
	string a = str.erase(2, 3);  //str.erase(pos, len); ����ɾ������ַ���
	cout << a << endl;
	
	string b = str.substr(2, 5); // str.substr(pos, len); �����ҵ����Ӵ�
	cout << b << endl;
	
	char *B = "bcs";
	int pos = str.find(B, 3); // str.find("aasd",pos);
	                          //����������ˣ������Ӵ��ĳ��ֵĵ�һ��λ�ã�û�Ҵ򷵻�-1
	cout << pos << endl;                              

	system("pause");
	return;
}