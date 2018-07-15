#include "iostream"
using namespace std;
#include "algorithm"
#include "vector"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//人家的代码 ==》差距
int TreeDepth1(TreeNode* pRoot){
	if (pRoot == NULL)   return 0;
	return max(1 + TreeDepth1(pRoot->left), 1 + TreeDepth1(pRoot->right));
}
//另外一种写法
int TreeDepth(TreeNode* pRoot)
{
	if (!pRoot)
		return 0;
	int l = TreeDepth(pRoot->left);
	int r = TreeDepth(pRoot->right);
	if (l == 0 || r == 0)     //当出现左子树为空时，直接不遍历了
		return 1 + l + r;
	return 1 + max(l, r);
}


void main36()
{
	system("pause");
}