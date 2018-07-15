#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

vector<int> tmp; vector<vector<int>> res;
void dfsFind(TreeNode *root, int remain)
{
	tmp.push_back(root->val); // 在遍历到节点时，将节点存入临时tmp中
	if (root->val == remain && !root->left && !root->right)
	{
		res.push_back(tmp);      
	}

	if (root->left) { dfsFind(root->left, remain - root->val);}   //遍历左子树
	if (root->right) { dfsFind(root->right, remain - root->val);} //遍历右子树
	tmp.pop_back();     //在叶子节点后，回退回去
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) //符合要求的路径树有许多条
{
	if (root)
	{
		dfsFind(root, expectNumber);
	}
	return res;
}

void main23()
{
	system("pause");
}