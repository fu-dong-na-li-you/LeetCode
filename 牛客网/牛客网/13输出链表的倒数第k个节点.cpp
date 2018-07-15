#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

	ListNode *p = pListHead;
	ListNode *pre = pListHead;
	int  length = 0;
	int m = k;
	while (p != NULL)
	{
		p = p->next;
		length++;

		if (m < 1)
		{
			pre = pre->next;
		}
		m--;
	}

	if (k > length) { return NULL; }

	return  pre;

} //当p先跑m个节点，，，，，然后pre再开始跑

void main13()
{
	system("pause");
}