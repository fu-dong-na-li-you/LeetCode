#include "iostream"
#include "vector"
using namespace std;

long InversePairsCore(vector<int> &data, vector<int> &copy, long start, long end){
	if (start == end)  // copy: ��������
	{
		return 0;  // �ݹ���ֹ����
	}

	long length = (end - start) / 2;
	long left = InversePairsCore(copy, data, start, start + length); // �ݹ飬�鲢���򣬲����㱾���������
	long right = InversePairsCore(copy, data, start + length + 1, end);
	long crossCount = 0;       // ��¼������������
	long i = start + length, j = end, temp = end;  //i��ǰ�벿�ֵ��±꣬j����벿�ֵ��±꣬temp������������±�

	while (i >= start && j >= start + length + 1) {   // ���ڽ��������ԣ���ͳ��һ�£�Ȼ�����ν��ϴ�ֵ�Ž���������
		if (data[i] > data[j]) {
			copy[temp--] = data[i--];
			crossCount += j - start - length;
		}
		else {
			copy[temp--] = data[j--];   // �����ڽ��������ԣ����ν��ϴ�ֵ�Ž���������
		}
	}
	while (i >= start) {
		copy[temp--] = data[i--];
	}
	while (j >= start + length + 1) {
		copy[temp--] = data[j--];
	}
	return (left + right + crossCount) % 1000000007; //��ֵ����ʱ����, ��ֹ���
}

int InversePairs(vector<int> &data) {
	if (data.size() == 0) return 0;
	else if (data.size() == 1) return 1;
	else {
		vector<int> copy(data);
		return InversePairsCore(copy, data, 0, data.size() - 1);
	}
}