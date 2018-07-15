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
		if (pPcur->next != NULL && pPcur->next->val == pPcur->val)  //��ǰ�ڵ����һ�ڵ��ֵ���
		{
			pNext = pPcur->next;  //��ֵ��pNext
			while (pNext != NULL && pNext->next != NULL && pNext->val == pNext->next->val)  
			{
				pNext = pNext->next;  //�ҵ�pNext��ָ��λ�ã�ɾ��pCur��pNext(����pCur��pNext)��һ����Ľڵ�ֵ
			}

			if (pHead == pPcur)  //���ͷ�ڵ����һ�ڵ���ȣ���ɾ��
				pHead = pNext->next;
			else
				pPre->next = pNext->next;  //������ǣ���pPreָ��pNext���½ڵ㣬ɾ���ظ��ڵ�
			
			pPcur = pNext->next; //����pCur��ָ��

		}

		else
		{
			pPre = pPcur;  //ָ����������ָ
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