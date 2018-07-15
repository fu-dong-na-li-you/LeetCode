#include <iostream>
using namespace std;


int GetMaxValue(int n, int m, int *w, int *v, int *c)
{
	{
		int row = n + 1;
		int col = m + 1;

		int i, j;    //ѭ������:ǰi����Ʒ�ܹ�װ��������Ϊj�ı�����

		//value[i][j]��ʾǰi����Ʒ��װ��������Ϊj�ı�������Ʒ������ֵ
		int **value = new int*[row];
		for (i = 0; i < row; i++)
			value[i] = new int[col];

		//��ʼ����0��
		for (j = 0; j < col; j++)
			value[0][j] = 0;

		//��ʼ����0��
		for (i = 0; i < row; i++)
			value[i][0] = 0;

		//����
		for (i = 1; i < row; i++)
		{
			for (j = 1; j<col; j++)
			{
				//w[i]>j,��i����Ʒ��װ�뱳��
				value[i][j] = value[i - 1][j];
				//w[i]<=j,�ҵ�i����Ʒװ�뱳����ļ�ֵ>value[i-1][j],���¼��ǰ����ֵ
				int temp = value[i - 1][j - w[i]] + v[i];
				if (w[i] <= j && temp>value[i][j])
					value[i][j] = temp;
			}
		}

		//������װ�����Ʒ
		j = m;
		for (i = row - 1; i > 0; i--)
		{
			if (value[i][j] > value[i - 1][j])
			{
				c[i] = 1;
				j -= w[i];
			}
		}

		//��¼����ֵ
		int nMaxVlaue = value[row - 1][col - 1];

		//�ͷŸö�ά����
		for (i = 0; i < row; i++)
		{
			delete[col]value[i];
			value[i] = NULL;
		}
		delete[] value;
		value = NULL;

		return nMaxVlaue;
	}
}

void test1()
{
	int n, C;
	while (cin >> n >> C)  //nΪ��Ʒ������CΪ������������
	{
		int *W = new int[n];
		int *V = new int[n];
		int *res = new int[n];
		for (int i = 0; i < n; i++)
		{
			res[i] = 0;
		}
		int w = 0, v = 0, i = 0;
		while (i < n)
		{
			cin >> w >> v;
			W[i] = w;
			V[i] = v;
			i++;
		}
		int value = GetMaxValue( n, C,W, V, res);
		cout << value << endl;
		for (int i = 0; i < n; i++)
			cout << res[i] << " ";
		cout << endl;
		delete W;
		delete V;
		delete res;
	}
}

int main_packect()
{
	test1();
	return 0;
}