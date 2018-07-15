#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* ReverseList(ListNode* pHead) {

	if (pHead == NULL) { return NULL; }
	if (pHead->next == NULL) { return pHead; }

	ListNode*  one_p = pHead;
	ListNode*  sec_p = one_p->next;
	ListNode*  th_p = sec_p->next;

	while (th_p != NULL)
	{
		sec_p->next = one_p;  //�ڶ����ڵ�ָ���һ���ڵ�
		one_p = sec_p;     //��ǰָ���һ���ڵ��ָ��ڶ����ڵ�
		sec_p = th_p;   //��ǰָ��ڶ����ڵ��ָ��������ڵ�

		th_p = th_p->next;  //��ǰָ��������ڵ��ָ����ĸ��ڵ�
	}
	pHead->next = NULL;
	sec_p->next = one_p; //������һ���ڵ�ָ�����ڶ��ڵ㣬��

	return sec_p;   //���ص�����һ���ڵ�
}

void main14()
{

	system("pause");
}