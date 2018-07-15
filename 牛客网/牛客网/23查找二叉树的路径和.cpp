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
	tmp.push_back(root->val); // �ڱ������ڵ�ʱ�����ڵ������ʱtmp��
	if (root->val == remain && !root->left && !root->right)
	{
		res.push_back(tmp);      
	}

	if (root->left) { dfsFind(root->left, remain - root->val);}   //����������
	if (root->right) { dfsFind(root->right, remain - root->val);} //����������
	tmp.pop_back();     //��Ҷ�ӽڵ�󣬻��˻�ȥ
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) //����Ҫ���·�����������
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