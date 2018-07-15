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
		sec_p->next = one_p;  //第二个节点指向第一个节点
		one_p = sec_p;     //以前指向第一个节点的指向第二个节点
		sec_p = th_p;   //以前指向第二个节点的指向第三个节点

		th_p = th_p->next;  //以前指向第三个节点的指向第四个节点
	}
	pHead->next = NULL;
	sec_p->next = one_p; //倒数第一个节点指向倒数第二节点，，

	return sec_p;   //返回倒数第一个节点
}

void main14()
{

	system("pause");
}