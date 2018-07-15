#include "iostream"
using namespace std;
#include "vector"
#include "string"
#include "cstdio"
#include "stack"

int evalRPN(vector<string> &tokens) {
	stack<int>  vNum;

	for (int i = 0; i < tokens.size(); i++) //最后一个必定是操作符
	{
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			if (vNum.size() < 2) { return 0;}
			int a = vNum.top(); vNum.pop();  //后入栈的数
			int b = vNum.top(); vNum.pop(); //这个是先进栈的数
			int res;
			
			if (tokens[i] == "+")      { res = a + b; }
			else if (tokens[i] == "-") { res = b - a; }
			else if (tokens[i] == "*") { res = a*b;}
			else                       { res = b/ a; }

			vNum.push(res);
		}
		else
		{
			vNum.push(atoi(tokens[i].c_str() ) ); //遇到数字，将字符串转成数字
		}
	}

	return vNum.top();
}