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


//�ݹ�汾
void postorder(TreeNode *root, vector<int> &v)
{
	if (root == NULL) { return;}
	postorder(root->left, v);
	postorder(root->right, v);
	v.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root) {
	vector<int> res;
	postorder(root, res);
	return res;
}

//�ǵݹ�汾
//˼·:ǰ����� ��->��->�� �ı�һ�� ��->��->�� ���תһ�¾��� ��->��->��
vector<int> postorderTraversal_1(TreeNode *root)
{
	vector<int> res;
	if (root == NULL) { return res; }

	stack<TreeNode *> s;
	s.push(root);

	while (s.size())
	{
		TreeNode *tmp = s.top();
		s.pop();
		res.push_back(tmp->val);

		if (tmp->left)   //������������ջ����ʵ�ֺ����������
			s.push(tmp->left);
		if (tmp->right)
			s.push(tmp->right);
	}
	reverse(res.begin(), res.end()); //��ת�����Ϊ ��->��->��
	return res;
}




void main06()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);

	node1.right = &node2;
	node2.left = &node3;
	vector<int> v = postorderTraversal_1(&node1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	system("pause");
}