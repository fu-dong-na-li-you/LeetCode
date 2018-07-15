#include "iostream"
using namespace std;
#include "string"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

void  Serialize60(TreeNode *root, string &str)  //递归时要加引用，不然值直接析构掉了
{
	if (root == NULL)
	{
		str =str + '#'; 
		return;
	}
	str =str + to_string(root->val);  //对一个字符串进行处理
	str =str + ',';

	Serialize60(root->left, str);
	Serialize60(root->right, str);
}

char* Serialize(TreeNode *root) {
	if (root == NULL) { return NULL;}
	string str;
	
	Serialize60(root, str);
	char*  ret = new char[str.size()+1];
	int i = 0;
	for (i = 0; i < str.size(); i++)
	{
		ret[i] = str[i];
	}
	ret[i] = '\0';  //在末尾添加0
	return ret;
}

TreeNode* Deserialize60(char **p)
{
	if (**p == '#')
	{
		(*p)++;
		return NULL;
	}
	int num = 0;
	while (**p != '\0' && **p != ',')
	{
		num = num * 10 + ((**p) - '0');
		(*p)++;
	}
	
	TreeNode* proot = new TreeNode(num);
	
	if (**p = ',') { (*p)++;}  //讨论**P分别为‘\0’和‘，’的情况
	else   { return proot;}
	
	proot->left = Deserialize60(p);
	proot->right = Deserialize60(p);

	return proot;
}

TreeNode* Deserialize(char *str) {
	if (str == NULL) { return NULL;}

	TreeNode *res = Deserialize60(&str);
	
	return res;
}


void printTree(TreeNode *pRoot)
{
	if (pRoot == NULL) { return;}
	cout << pRoot->val << "   ";
	printTree(pRoot->left);
	printTree(pRoot->right);
}

void  main60()
{
	TreeNode node1(11);
	TreeNode node2(22);
	TreeNode node3(33);
	TreeNode node4(44);
	TreeNode node5(55);
	TreeNode node6(66);
	TreeNode node7(77);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;

	char* a= Serialize(&node1);
	char* tmp = a;
	while (*a)
	{
		cout << *a << " ";
		a++;
	}
	cout << endl;
	TreeNode *head = Deserialize(tmp);
	printTree(head);


	system("pause");
}