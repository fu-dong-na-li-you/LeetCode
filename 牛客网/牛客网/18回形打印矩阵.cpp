#include "iostream"
using namespace std;
#include "vector"

vector<int> printMatrix(vector<vector<int> > matrix) {

	vector<int>  v;
	int  row = matrix.size();
	int  col = matrix[0].size();
	if (row == 0 || col == 0) { return v; }

	int left = 0, right = col - 1, top = 0, buttom = row - 1;
	while (left <= right  && top <= buttom)
	{
		for (int i = left; i <= right; i++)  { v.push_back(matrix[top][i]); }  //从左到右

		for (int i = top + 1; i <= buttom; i++) { v.push_back(matrix[i][right]); }  //从上到下

		if (buttom != top)    //防止单行，往回打印
		for (int j = right - 1; j >= left; j--) { v.push_back(matrix[buttom][j]); } //从右到左

		if (right != left)  //防止单列
		for (int j = buttom - 1; j > top; j--)  { v.push_back(matrix[j][left]); } //从下到上

		//循环一圈后，向内圈遍历
		left++;   right--;   top++;  buttom--;
	}

	return v;

}


void main18()
{
	system("pause");
}