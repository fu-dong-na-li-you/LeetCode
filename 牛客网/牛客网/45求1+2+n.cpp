#include "iostream"
using namespace std;

//�˼ҵĴ�

//1.�������߼���Ķ�·����ʵ�ֵݹ���ֹ�� 
//2.��n == 0ʱ��(n > 0) && ((sum += Sum_Solution(n - 1)) > 0)ִֻ��ǰ����жϣ�Ϊfalse��Ȼ��ֱ�ӷ���0��
//3.��n > 0ʱ��ִ��sum += Sum_Solution(n - 1)��ʵ�ֵݹ����Sum_Solution(n)��

int Sum_Solution(int n) {
	int sum = n;
	bool ans = (n > 0) && ((sum =sum + Sum_Solution(n - 1)) > 0);
	return sum;
}


