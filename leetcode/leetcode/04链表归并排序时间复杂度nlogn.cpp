#include "iostream"
using namespace  std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
��Ϊ��ĿҪ���Ӷ�ΪO(nlogn),�ʿ��Կ��ǹ鲢�����˼�롣
�鲢�����һ�㲽��Ϊ��
1�������������飨����ȡ�е㲢һ��Ϊ����
2���ݹ�ض���벿�ֽ��й鲢����
3���ݹ�ض��Ұ벿�ֽ��й鲢����
4���������벿�ֽ��кϲ���merge��,�õ����*/

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