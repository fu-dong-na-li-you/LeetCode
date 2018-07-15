#include<cstdio>
#include<iostream>
#include <vector>
#include<string>
using namespace std;
/*返回值： 最大公共子串长度
* s: 原回文串
* res: 反转回文串
* c: 公共子串长度值
*/
int longCommon(string& s) {
	string res = s;
	reverse(res.begin(), res.end());
	int size = s.length();
	vector<vector<int>> c(size + 1, vector<int>(size + 1));

	/* c[i,j] = 0							  i = 0 or j = 0
	*  c[i,j] = c[i-1,j-1]+1					  xi = xj
	*  c[i, j] = max(c[i, j - 1],c[i - 1, j]) xi != xj
	*动态规划-----------
	/*最长公共子序列的结构有如下表示：
	*设序列X=和Y=的一个最长公共子序列Z=，则：
	*若 xm=yn，则 zk=xm=yn，且Zk-1是Xm-1和Yn-1的最长公共子序列；
	*若 yn≠xm且 zk≠xm ，则 Z是 Xm-1和 Y的最长公共子序列；
	*若 xm≠yn且 zk≠yn ，则 Z是 X和 Yn-1的最长公共子序列；
	*
	*
	*当xm≠yn时，必须解两个子问题，即找出Xm-1和Y的一个最长公共子序列及X和Yn-1的一个最长公共子序列。
	*这两个公共子序列中较长者即为X和Y的一个最长公共子序列。
	*在计算X和Y的最长公共子序列时，可能要计算出X和Yn-1以及Xm-1和Y的最长公共子序列。
	*而这两个子问题都包含一个公共子问题，即计算Xm-1和Yn-1的最长公共子序列。
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