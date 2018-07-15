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

bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL && pRoot2 == NULL) { return true; }

	if (pRoot1 == NULL || pRoot2 == NULL) { return false; }

	if (pRoot1->val != pRoot2->val)  { return false; }

	return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
}



bool isSymmetrical57(TreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}



void main57()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(2);
	TreeNode node4(3);
	TreeNode node5(4);
	TreeNode node6(4);
	TreeNode node7(3);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	//node3.right = &node7;

	bool a = isSymmetrical57(&node1);
	if (a)
	{
		cout << "shi" << endl;
	}
	else
	{
		cout << "fou" << endl;
	}

	system("pause");
}