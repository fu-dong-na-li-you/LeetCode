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
	midSearch(cur->left, pre);   //在到达树的最小子树的时候，pre为最左端的节点，cur为树根

	cur->left = pre;    
	if (pre) 
	{ pre->right = cur; } //建立双向链表

	pre = cur;  //指针进行移动

	midSearch(cur->right, pre);  //pre为树根，cur为右端的节点

}

//采用中序遍历
TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL) { return NULL; }

	TreeNode *  pre = NULL;
	midSearch(pRootOfTree, pre);

	TreeNode* res = pRootOfTree;
	while (res->left)
	{
		res = res->left;  //到达二叉树的最左端
	}
	return res;
}

void main24()
{
	system("pause");
}