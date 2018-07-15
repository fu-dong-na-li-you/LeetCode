#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

 struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {	
		}
};

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> res;
	if (head == NULL) { return res;}
	while (head != NULL)
	{
		res.push_back(head->val);
		head = head->next;
	}
	reverse(res.begin(), res.end());
	return res;
}


void main03()
{

	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	vector<int> v = printListFromTailToHead(&node1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}

	system("pause");
}