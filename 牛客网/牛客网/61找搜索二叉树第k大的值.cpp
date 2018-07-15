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

static int num = 0;
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot)           //中序遍历，查找第k个点
	{
		TreeNode* node = KthNode(pRoot->left, k);
		if (node != NULL) { return node;}

		num++;
		if (num == k) { return pRoot;}

		node = KthNode(pRoot->right, k);
		if (node != NULL) { return node;}
	}

	return NULL;
}


void main61()
{

	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;

	TreeNode*  tree = KthNode(&node1, 3);

	cout << tree->val << endl;
	system("pause");
}