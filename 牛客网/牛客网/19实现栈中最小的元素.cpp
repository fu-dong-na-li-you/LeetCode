#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

vector<int> v1, v2;
void push(int value) {
	v1.push_back(value);
}
void pop() {
	v1.pop_back();
}
int top() {
	return v1.back();
}
int min() {
	v2 = v1;
	sort(v2.begin(), v2.end());
	return  v2[0];
}

void main19()
{
	system("pause");
}