#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)   { return pHead2; }  //表明较小的节点先遍历到尾部，，需要指向较大的节点
	if (pHead2 == NULL)   { return pHead1; }

	if (pHead1->val <= pHead2->val)   //因为递增，，谁小就优先遍历谁
	{
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
	else
	{
 		pHead2->next = Merge(pHead1, pHead2->next);
		return pHead2;
	}

}

void main15()
{
	system("pause");
}