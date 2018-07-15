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

	while (pFast != NULL && pLow != pFast)  //�ҵ��ڻ��������Ľڵ�
	{
		pFast = pFast->next;
		pLow = pLow->next;
		if (pFast != NULL)
		{
			pFast = pFast->next;
		}
	}

	if (pFast == NULL) { return NULL; }  //֤��������û�л�

	int num = 1;        //ͳ�������л��Ľڵ���
	pFast = pFast->next;
	while (pFast != pLow)
	{
		pFast = pFast->next;
		++num;
	}
	
	pFast = pHead; pLow = pHead;     //�������ڵ�����ָ��ͷ�ڵ�
	for (int i = 0; i < num; i++)  //�ÿ�Ľڵ�����num���ڵ�
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