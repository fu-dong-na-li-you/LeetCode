#include "iostream"
using namespace std;
#include "vector"
#include "string"
#include "cstdio"
#include "stack"

int evalRPN(vector<string> &tokens) {
	stack<int>  vNum;

	for (int i = 0; i < tokens.size(); i++) //���һ���ض��ǲ�����
	{
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			if (vNum.size() < 2) { return 0;}
			int a = vNum.top(); vNum.pop();  //����ջ����
			int b = vNum.top(); vNum.pop(); //������Ƚ�ջ����
			int res;
			
			if (tokens[i] == "+")      { res = a + b; }
			else if (tokens[i] == "-") { res = b - a; }
			else if (tokens[i] == "*") { res = a*b;}
			else                       { res = b/ a; }

			vNum.push(res);
		}
		else
		{
			vNum.push(atoi(tokens[i].c_str() ) ); //�������֣����ַ���ת������
		}
	}

	return vNum.top();
}