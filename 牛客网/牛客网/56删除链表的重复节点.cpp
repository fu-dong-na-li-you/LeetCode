#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL ) { return NULL;}

	ListNode* pPre = NULL, *pPcur = pHead, *pNext = NULL;
	
	while (pPcur != NULL)
	{
		if (pPcur->next != NULL && pPcur->next->val == pPcur->val)  //当前节点和下一节点的值相等
		{
			pNext = pPcur->next;  //赋值给pNext
			while (pNext != NULL && pNext->next != NULL && pNext->val == pNext->next->val)  
			{
				pNext = pNext->next;  //找到pNext的指针位置，删除pCur和pNext(包括pCur和pNext)这一区域的节点值
			}

			if (pHead == pPcur)  //如果头节点和下一节点相等，则删除
				pHead = pNext->next;
			else
				pPre->next = pNext->next;  //如果不是，则pPre指向pNext的新节点，删除重复节点
			
			pPcur = pNext->next; //更新pCur的指向

		}

		else
		{
			pPre = pPcur;  //指针依次往下指
			pPcur = pPcur->next;
		}
	}

	return pHead;
}

void  main56()
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(3);
	ListNode node5(4);
	ListNode node6(4);
	ListNode node7(5);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node6.next = &node7;

	ListNode* p = deleteDuplication(&node1);
	while (p)
	{
		cout << p->val << "  ";
		p = p->next;
	}

	system("pause");
}