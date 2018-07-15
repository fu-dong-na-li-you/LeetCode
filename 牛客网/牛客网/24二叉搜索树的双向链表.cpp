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

void  midSearch(TreeNode* cur, TreeNode *&pre)   //
{
	if (cur == NULL) { return; }
	midSearch(cur->left, pre);   //�ڵ���������С������ʱ��preΪ����˵Ľڵ㣬curΪ����

	cur->left = pre;    
	if (pre) 
	{ pre->right = cur; } //����˫������

	pre = cur;  //ָ������ƶ�

	midSearch(cur->right, pre);  //preΪ������curΪ�Ҷ˵Ľڵ�

}

//�����������
TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL) { return NULL; }

	TreeNode *  pre = NULL;
	midSearch(pRootOfTree, pre);

	TreeNode* res = pRootOfTree;
	while (res->left)
	{
		res = res->left;  //����������������
	}
	return res;
}

void main24()
{
	system("pause");
}