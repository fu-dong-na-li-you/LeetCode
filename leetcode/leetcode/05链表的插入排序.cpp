#include "iostream"
using namespace std;
#include "list"

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x),next(NULL){}
};

//对一个链表进行排序，，哈哈哈，，机智
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


//使用插入排序对链表进行排序 
ListNode *insertionSortList(ListNode *head) {
	if (!head || !head->next) return head;
	ListNode dummyHead(0), *p;
	dummyHead.next = insertionSortList(head->next);
	p = &dummyHead;

	while (p && p->next && head->val > p->next->val){ //列表从小到大排序
		p = p->next;
	}
	head->next = p->next; 
	p->next = head;   //保证dummyHead的下一个节点总是最小的节点

	return dummyHead.next;   //返回当前节点的地址
}

/* p->next（1）表示指向下一个节点（2）表示下一个节点的地址 */
