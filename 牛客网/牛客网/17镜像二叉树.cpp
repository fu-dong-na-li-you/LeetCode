#include "iostream"
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL) { return;}
		
	TreeNode *tmp;
	tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;
	//cout << pRoot->val << endl;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

void main17()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;

	Mirror(&node1);
	system("pause");
}