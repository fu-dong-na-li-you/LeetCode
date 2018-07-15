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
		for (int i = left; i <= right; i++)  { v.push_back(matrix[top][i]); }  //������

		for (int i = top + 1; i <= buttom; i++) { v.push_back(matrix[i][right]); }  //���ϵ���

		if (buttom != top)    //��ֹ���У����ش�ӡ
		for (int j = right - 1; j >= left; j--) { v.push_back(matrix[buttom][j]); } //���ҵ���

		if (right != left)  //��ֹ����
		for (int j = buttom - 1; j > top; j--)  { v.push_back(matrix[j][left]); } //���µ���

		//ѭ��һȦ������Ȧ����
		left++;   right--;   top++;  buttom--;
	}

	return v;

}


void main18()
{
	system("pause");
}