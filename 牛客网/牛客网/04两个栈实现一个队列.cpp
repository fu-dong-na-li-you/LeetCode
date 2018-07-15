#include "iostream"
using namespace std;
#include "stack"

class Solution04
{
public:  //如果stack2为空，则将stack1的数据全部拷贝进去，如果stack2不为空，则直接从stack2中弹出
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