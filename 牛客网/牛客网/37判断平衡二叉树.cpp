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

int  getTreeDepth(TreeNode *p)   //�����������������ĸ߶�
{
	if (p == NULL) { return 0; }
	int    leftDepth = getTreeDepth(p->left);
	int   rightDepth = getTreeDepth(p->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;  //ע���ڱ���������ʱ������ֵ��ʹ��
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == NULL) { return  true; }

	int   leftDepth = getTreeDepth(pRoot->left);       //�������ĸ߶�
	int   rightDepth = getTreeDepth(pRoot->right);  //�������ĸ߶�

	if (leftDepth + 1 < rightDepth || leftDepth > rightDepth + 1)  //���������ĸ߶Ȳ��ܳ���2
	{
		return false;
	}
	else
	{
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);   //����������
	}
}