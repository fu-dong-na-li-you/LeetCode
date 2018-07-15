#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* walkstep(ListNode *p, int num)
{
	for (int i = 0; i < num; i++)
	{
		p = p->next;
	}
	return p;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL || pHead2 == NULL) { return NULL;}

	int len1 = 0, len2 = 0;
	ListNode*  p1 = pHead1;
	ListNode*  p2 = pHead2;
	while (p1 != NULL)
	{
		++len1;
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		++len2;
		p2 = p2->next;
	}
	
	if (len1 >= len2) { pHead1 = walkstep(pHead1, len1 - len2);}  //让较长的链表先走一段距离
	else {     pHead2 = walkstep(pHead2, len2 - len1); }

	while (pHead1 != NULL)
	{
		if (pHead1 == pHead2) { return pHead1;}  //找到公共节点，则直接返回
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}

	return NULL;
}

void  main34()
{
	system("pause");
}