#include "iostream"
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

ListNode *Middle(ListNode *head)
{
	ListNode *pslow = head;
	ListNode *pfast = head->next;
	while (pfast != NULL && pfast->next != NULL)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	return pslow;
}



void reorderList(ListNode *head){
	if (head == NULL) { return;}
	ListNode *middleNode = Middle(head);  //快慢指针找到中间节点


}


