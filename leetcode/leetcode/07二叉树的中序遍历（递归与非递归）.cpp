#include "iostream"
using namespace std;
#include "vector"
#include "stack"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

//中序遍历非递归版
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode *> st;
	TreeNode *curr = root;

	while (curr || !st.empty()){ //curr不等于null 或者 st不能为空
		
		while (curr){  //如果右子树不为空，则遍历左子树
			st.push(curr);
			curr = curr->left;
		}
		//将左子树节点的值存入res中，并且弹出栈
		curr = st.top();
		st.pop();
		res.push_back(curr->val);
		
		curr = curr->right;
	}
	return res;
}

void main()
{

	system("pause");
}