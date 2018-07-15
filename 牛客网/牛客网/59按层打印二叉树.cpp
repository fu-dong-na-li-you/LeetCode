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

vector<vector<int> > Print59(TreeNode* pRoot) {
	vector<vector<int>>  res;
	if (pRoot == NULL) { return res;}
	queue<TreeNode *>  que;
	que.push(pRoot);

	while (!que.empty())
	{
		vector<int> vec;
		int len = que.size();
		for (int i = 0; i < len; i++)
		{
			TreeNode *tmp = que.front();
			vec.push_back(tmp->val);
			que.pop();
			if (tmp->left) { que.push(tmp->left); }
			if (tmp->right) { que.push(tmp->right);}

		}
		
		res.push_back(vec);
	}
	return res;
}

void  main59()
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

	vector<vector<int>>   res = Print59(&node1);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << endl;
		}
	}

	system("pause");
}