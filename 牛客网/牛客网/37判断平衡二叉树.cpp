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

int  getTreeDepth(TreeNode *p)   //求左子树和右子树的高度
{
	if (p == NULL) { return 0; }
	int    leftDepth = getTreeDepth(p->left);
	int   rightDepth = getTreeDepth(p->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;  //注意在遍历二叉树时，返回值的使用
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == NULL) { return  true; }

	int   leftDepth = getTreeDepth(pRoot->left);       //左子树的高度
	int   rightDepth = getTreeDepth(pRoot->right);  //右子树的高度

	if (leftDepth + 1 < rightDepth || leftDepth > rightDepth + 1)  //左右子树的高度不能超过2
	{
		return false;
	}
	else
	{
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);   //遍历整个树
	}
}