#include<cstdio>
#include<iostream>
#include <vector>
#include<string>
using namespace std;
/*����ֵ�� ��󹫹��Ӵ�����
* s: ԭ���Ĵ�
* res: ��ת���Ĵ�
* c: �����Ӵ�����ֵ
*/
int longCommon(string& s) {
	string res = s;
	reverse(res.begin(), res.end());
	int size = s.length();
	vector<vector<int>> c(size + 1, vector<int>(size + 1));

	/* c[i,j] = 0							  i = 0 or j = 0
	*  c[i,j] = c[i-1,j-1]+1					  xi = xj
	*  c[i, j] = max(c[i, j - 1],c[i - 1, j]) xi != xj
	*��̬�滮-----------
	/*����������еĽṹ�����±�ʾ��
	*������X=��Y=��һ�������������Z=����
	*�� xm=yn���� zk=xm=yn����Zk-1��Xm-1��Yn-1������������У�
	*�� yn��xm�� zk��xm ���� Z�� Xm-1�� Y������������У�
	*�� xm��yn�� zk��yn ���� Z�� X�� Yn-1������������У�
	*
	*
	*��xm��ynʱ����������������⣬���ҳ�Xm-1��Y��һ������������м�X��Yn-1��һ������������С�
	*�����������������нϳ��߼�ΪX��Y��һ������������С�
	*�ڼ���X��Y�������������ʱ������Ҫ�����X��Yn-1�Լ�Xm-1��Y������������С�
	*�������������ⶼ����һ�����������⣬������Xm-1��Yn-1������������С�
	*/
	for (int i = 1; i <= size; ++i)
	for (int j = 1; j <= size; ++j)
	{
		if (s[i - 1] == res[j - 1]) {
			c[i][j] = c[i - 1][j - 1] + 1;

		}
		else if (c[i - 1][j] > c[i][j - 1]) {
			c[i][j] = c[i - 1][j];

		}
		else if (c[i - 1][j] < c[i][j - 1]) {
			c[i][j] = c[i][j - 1];

		}
		else {//c[i - 1][j] == c[i][j - 1]
			c[i][j] = c[i][j - 1];
		}
	}
	return c[size][size];
}


int main_jingdong2(){
	string x;
	cin >> x;
	int origin_long = x.length();
	int len = longCommon(x);
	cout << len << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;
}