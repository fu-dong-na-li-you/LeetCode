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

static int num = 0;
void DFS(TreeNode *pRoot, vector<int> &v)
{
	num++;
	if (pRoot->left == NULL && pRoot->right == NULL) { 
		v.push_back(num);     //��������Ҷ�ӽڵ�ʱ�������Ĳ���������
	}

	if (pRoot->left) { DFS(pRoot->left, v); }   //����������
	if (pRoot->right) { DFS(pRoot->right, v);}  //����������
	num--;               //�ڱ�����Ҷ�ӽڵ�ʱ���˻�
}

int TreeDepth(TreeNode* pRoot)
{
	vector<int>  v;
	DFS(pRoot, v);
	vector<int>::iterator it = max_element(v.begin(), v.end());
	
	return *it;
}

/*
int TreeDepth(TreeNode* pRoot){
	if (!pRoot) return 0;
	return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
}
*/

void main_test2()
{
	system("pause");
}