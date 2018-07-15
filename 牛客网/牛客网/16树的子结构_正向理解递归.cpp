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

bool isSubtree(TreeNode* pRootA, TreeNode* pRootB)
{
	if (pRootB == NULL) { return true;}    //当子树为空时，说明遍历完成，找到子结构
	if (pRootA == NULL) { return false;}   

	if (pRootA->val != pRootB->val) { return false;}

	return isSubtree(pRootA->left, pRootB->left) || isSubtree(pRootA->right, pRootB->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL) { return false;}  //子树或者母树为空

	return isSubtree(pRoot1, pRoot2) ||         //判断当前的母树中有没有子结构  
		HasSubtree(pRoot1->right, pRoot2)||    
		HasSubtree(pRoot1->left, pRoot2);    //母树遍历右子树
}


void main16()
{

}