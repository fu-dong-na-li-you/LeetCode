#include "iostream"
using namespace std;
#include "list"

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x),next(NULL){}
};

//��һ������������򣬣���������������
ListNode *insertionSortList_1(ListNode *head)
{
	if (head == NULL || head->next == NULL) return head;
	list<int> v;
	for (ListNode *p = head; p != NULL; p = p->next){
		v.push_back(p->val);
	}
	v.sort();
	for (ListNode *p = head; p != NULL; p = p->next){
		p->val = v.front();
		v.pop_front();
	}
	return head;
}


//ʹ�ò������������������� 
ListNode *insertionSortList(ListNode *head) {
	if (!head || !head->next) return head;
	ListNode dummyHead(0), *p;
	dummyHead.next = insertionSortList(head->next);
	p = &dummyHead;

	while (p && p->next && head->val > p->next->val){ //�б��С��������
		p = p->next;
	}
	head->next = p->next; 
	p->next = head;   //��֤dummyHead����һ���ڵ�������С�Ľڵ�

	return dummyHead.next;   //���ص�ǰ�ڵ�ĵ�ַ
}

/* p->next��1����ʾָ����һ���ڵ㣨2����ʾ��һ���ڵ�ĵ�ַ */
