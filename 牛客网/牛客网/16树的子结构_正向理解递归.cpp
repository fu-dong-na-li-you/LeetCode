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
	if (pRootB == NULL) { return true;}    //������Ϊ��ʱ��˵��������ɣ��ҵ��ӽṹ
	if (pRootA == NULL) { return false;}   

	if (pRootA->val != pRootB->val) { return false;}

	return isSubtree(pRootA->left, pRootB->left) || isSubtree(pRootA->right, pRootB->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL) { return false;}  //��������ĸ��Ϊ��

	return isSubtree(pRoot1, pRoot2) ||         //�жϵ�ǰ��ĸ������û���ӽṹ  
		HasSubtree(pRoot1->right, pRoot2)||    
		HasSubtree(pRoot1->left, pRoot2);    //ĸ������������
}


void main16()
{

}