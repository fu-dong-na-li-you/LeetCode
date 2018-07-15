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

//��������ǵݹ��
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode *> st;
	TreeNode *curr = root;

	while (curr || !st.empty()){ //curr������null ���� st����Ϊ��
		
		while (curr){  //�����������Ϊ�գ������������
			st.push(curr);
			curr = curr->left;
		}
		//���������ڵ��ֵ����res�У����ҵ���ջ
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