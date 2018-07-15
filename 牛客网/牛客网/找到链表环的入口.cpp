#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL ) { return NULL;}
	ListNode *pFast = pHead->next;
	ListNode *pLow = pHead;

	while (pFast != NULL && pLow != pFast)  //找到在环中相遇的节点
	{
		pFast = pFast->next;
		pLow = pLow->next;
		if (pFast != NULL)
		{
			pFast = pFast->next;
		}
	}

	if (pFast == NULL) { return NULL; }  //证明链表中没有环

	int num = 1;        //统计链表中环的节点数
	pFast = pFast->next;
	while (pFast != pLow)
	{
		pFast = pFast->next;
		++num;
	}
	
	pFast = pHead; pLow = pHead;     //让两个节点重新指向头节点
	for (int i = 0; i < num; i++)  //让快的节点先跑num个节点
	{
		pFast = pFast->next;
	}

	while (pFast != pLow)
	{
		pFast = pFast->next;
		pLow = pLow->next;
	}

	return pLow;
}

void main_test3()
{
	system("pause");
}