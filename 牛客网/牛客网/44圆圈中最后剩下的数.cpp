#include "iostream"
using namespace std;
#include "vector"

//人家的代码，哭死
int LastRemaining_Solution2(int n, int m)
{
	if (n == 0) { return -1;}
	int s = 0;
	for (int i = 2; i <= n; i++)
	{
		s = (s + m) % i;
	}
	return s;
}


//我的代码
int LastRemaining_Solution(int n, int m)
{
	if (n == 0) { return -1;}
	vector<int> tmp(n);
	for (int i = 0; i < n; i++)
	{
		tmp[i] = i;
	}

	int len = n, index = -1, step = 0; //index为tmp数组的下角标， step记录移动了多少格，len为剩下数字
	while (len != 0)  //直到最后一个数出局，则停止
	{
		index++;
		if (index == n ) { index = 0;}  //当下角标指到数组末尾时，再返回到最前面
		if (tmp[index] == -1) { continue;}  //当遇到-1时，表明该位置已经出局，直接跳过

		step++;
		if (step == m)    //计数
		{
			tmp[index] = -1;   //表示出局
			len--;    //有效数少了一个
			step = 0;  //重新计数
		}

	}
	return index;
}



void  main44()
{
	int res = LastRemaining_Solution(5, 3);
	cout << res << endl;

	system("pause");
}