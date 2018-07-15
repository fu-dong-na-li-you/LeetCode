#include "iostream"
using namespace std;
#include "algorithm"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


//modify
int run(TreeNode *root) {
	if (!root)
		return 0;
	int l = run(root->left);
	int r = run(root->right);
	if (l == 0 || r == 0)
		return 1 + l + r;
	return 1 + min(l, r);
}


void main01()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	//TreeNode node6(6);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node3;
	node2.right = &node4;
	node3.left = &node5;

	cout << run(&node1) << endl;
	system("pause");
}
