#include "iostream"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* EntryNodeOfLoop55(ListNode* pHead)
{
	if (pHead == NULL) { return NULL;}
	ListNode *pfast = pHead->next, *plow = pHead;  //����ָ��һ�����ڻ�������
	while (pfast != NULL  && pfast != plow)
	{
		pfast = pfast->next;
		plow = plow->next;
		if (pfast != NULL)
			pfast = pfast->next;
	}

	int num = 1; //���㻷�Ľڵ���
	if (pfast == plow && pfast != NULL)  //���û�л�����pfastָ��null
	{
		ListNode *tmp = pfast->next;
		while (tmp != pfast)
		{
			tmp = tmp->next;
			num++;
		}
	}
	else  //���û�л����򷵻�Ϊ��
	{
		return NULL;
	}
	
	ListNode* pNode1 = pHead, *pNode2 = pHead;  //�õ�һ���ڵ�ָ������num���ڵ�
	for (int i = 0; i < num; i++)
	{
		pNode1 = pNode1->next;
	}

	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return  pNode1;
}

void  main55()
{

	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	ListNode node6(6);
	ListNode node7(7);
	
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node3;
	node7.next = &node1;

	ListNode*  p = EntryNodeOfLoop55(&node7);
	if (p)
		cout << p->val << endl;
	else
		cout << "NO" << endl;

	system("pause");
}