#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "queue"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int>>  res;
	if (pRoot == NULL) { return res;}
	queue<TreeNode *>   q;
	bool  flag = false;
	
	q.push(pRoot);
	while (!q.empty())
	{
		vector<int>   vec;
		int len = q.size();  // 计算一层中的节点个数
		
		for (int i = 0; i < len ; i++)   //将一层节点数存入vec中，同时存下一层的节点地址
		{
			TreeNode *tmp = q.front();
			q.pop();
			vec.push_back(tmp->val);
			if (tmp->left)  { q.push(tmp->left);}
			if (tmp->right) { q.push(tmp->right);}
		}

		if (flag)  { reverse(vec.begin(), vec.end()); }  //按照层进行翻转
		flag = !flag;

		res.push_back(vec);   //存入最终结果
	}
	return res;
}

void main58()
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

	vector<vector<int>>   res = Print(&node1);
	
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j]<<endl;
		}
	}


	system("pause");
}