#include "iostream"
using namespace std;

int main_tengxun()
{
	int len;
	cin >> len;
	int A, B, X, Y;
	cin >> A; cin >> X; cin >> B; cin >> Y;

	int num1 = 0, num2 = 0;
	int flag = 0; //��ʾû���ҵ�
	
	if (X != 0)
	{
		for (int i = 0; i < X; i++)  //���˶��ٸ�X
		{
			for (int j = 0; j < Y; j++) //���˶��ٸ�Y
			{
				if (len == (i*A + j*B))
				{
					num1 = i;//���˶��ٸ�X
					num2 = j; //���˶��ٸ�Y	
				}
			}
		}

		int numerator = 1, denominator = 1;
		for (int k = 0; k < num1; k++) //��X�����
		{
			numerator = numerator *(X - k);
			denominator = denominator * (k + 1);
		}
		long res1 = numerator / denominator;

		int numeratorY = 1, denominatorY = 1; //��Y�����
		for (int k = 0; k < num2; k++)
		{
			numeratorY = numeratorY *(X - k);
			denominatorY = denominatorY * (k + 1);
		}
		long res2 = numeratorY / denominatorY;

		int res = (res1*res2) % 1000000007;
		cout << res << endl;

	}
	else if (Y != 0)
	{
		for (int i = 0; i < Y; i++)  //���˶��ٸ�X
		{
			for (int j = 0; j < X; j++) //���˶��ٸ�Y
			{
				if (len == (i*B + j*A))
				{
					num1 = i;//���˶��ٸ�X
					num2 = j; //���˶��ٸ�Y	
				}
			}
		}

		int numerator = 1, denominator = 1;
		for (int k = 0; k < num1; k++) //��X�����
		{
			numerator = numerator *(X - k);
			denominator = denominator * (k + 1);
		}
		long res1 = numerator / denominator;

		int numeratorY = 1, denominatorY = 1; //��Y�����
		for (int k = 0; k < num2; k++)
		{
			numeratorY = numeratorY *(X - k);
			denominatorY = denominatorY * (k + 1);
		}
		long res2 = numeratorY / denominatorY;

		int res = (res1*res2) % 1000000007;
		cout << res << endl;

	}

	else
	{
		cout << 0 << endl;
	}

	system("pause");
	return 0;
}