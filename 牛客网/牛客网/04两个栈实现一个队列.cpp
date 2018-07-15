#include "iostream"
using namespace std;
#include "stack"

class Solution04
{
public:  //���stack2Ϊ�գ���stack1������ȫ��������ȥ�����stack2��Ϊ�գ���ֱ�Ӵ�stack2�е���
	void push(int node) {

		stack1.push(node);
	}

	int pop() {

		if (stack2.empty())  {
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		int a = stack2.top();
		stack2.pop();
		return a;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};


void main04()
{
	system("pause");
}