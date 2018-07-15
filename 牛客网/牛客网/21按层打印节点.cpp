#include "iostream"
using namespace std;
#include "vector"
#include "queue"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> res;
	if (root == NULL) { return res;}
	queue<TreeNode *>  q;
	q.push(root);  //存放所有二叉树的节点

	while (!q.empty())
	{
		TreeNode *tmp = q.front();
		res.push_back(tmp->val);  //将当前节点存入结果中
		q.pop();

		if (tmp->left) { q.push(tmp->left);}
		if (tmp->right) { q.push(tmp->right);}
	}
	return res;
}

void  main21()
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
	vector<int> v = PrintFromTopToBottom(&node1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
	system("pause");
}