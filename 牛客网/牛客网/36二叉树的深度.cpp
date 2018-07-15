#include "iostream"
using namespace std;
#include "algorithm"
#include "vector"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//�˼ҵĴ��� ==�����
int TreeDepth1(TreeNode* pRoot){
	if (pRoot == NULL)   return 0;
	return max(1 + TreeDepth1(pRoot->left), 1 + TreeDepth1(pRoot->right));
}
//����һ��д��
int TreeDepth(TreeNode* pRoot)
{
	if (!pRoot)
		return 0;
	int l = TreeDepth(pRoot->left);
	int r = TreeDepth(pRoot->right);
	if (l == 0 || r == 0)     //������������Ϊ��ʱ��ֱ�Ӳ�������
		return 1 + l + r;
	return 1 + max(l, r);
}


void main36()
{
	system("pause");
}