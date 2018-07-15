#include "iostream"
using namespace  std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
因为题目要求复杂度为O(nlogn),故可以考虑归并排序的思想。
归并排序的一般步骤为：
1）将待排序数组（链表）取中点并一分为二；
2）递归地对左半部分进行归并排序；
3）递归地对右半部分进行归并排序；
4）将两个半部分进行合并（merge）,得到结果*/

ListNode* findMiddle(ListNode* head){
	ListNode* chaser = head;
	ListNode* runner = head->next;
	while (runner != NULL && runner->next != NULL){
		chaser = chaser->next;
		runner = runner->next->next;
	}
	return chaser;
}

ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
	if (left == NULL){
		return right;
	}
	if (right == NULL){
		return left;
	}
	ListNode* dummy = new ListNode(0);
	ListNode* head = dummy;
	while (left != NULL && right != NULL){
		if (left->val > right->val){
			head->next = right;
			right = right->next;
		}
		else{
			head->next = left;
			left = left->next;
		}
		head = head->next;
	}
	if (left == NULL){
		head->next = right;
	}
	if (right == NULL){
		head->next = left;
	}
	return dummy->next;
}

ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL){
		return head;
	}
	ListNode* middle = findMiddle(head);
	ListNode* right = sortList(middle->next);
	middle->next = NULL;
	ListNode* left = sortList(head);
	return mergeTwoLists(left, right);
}