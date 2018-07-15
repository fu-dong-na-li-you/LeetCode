#include "iostream"
using namespace std;
#include "vector"
#include "stack"

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int i) : val(i), left(NULL), right(NULL){}
};

void preorder(TreeNode *root, vector<int> &v)
{
	if (root == NULL) { return;}
	v.push_back(root->val);
	preorder(root->left, v);
	preorder(root->right, v);
}

//递归版  前序遍历
vector<int> preorderTraversal(TreeNode *root) {
	vector<int> res;
	preorder(root, res);
	return res;
}

//非递归版本的前序遍历
vector<int> preorderTraversal_1(TreeNode *root) {
	vector<int> res;
	if (root == NULL) { return res;}
	stack<TreeNode *> st;
	st.push(root);

	while (st.size())
	{
		TreeNode *tmp = st.top();
		st.pop();
		res.push_back(tmp->val);

		if (tmp->right) { st.push(tmp->right); } //先进，后弹出栈
		if (tmp->left)  { st.push(tmp->left); }
	}
	return res;
}

void main()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);

	node1.right = &node2;
	node2.left = &node3;
	vector<int> v = preorderTraversal_1(&node1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	system("pause");
}