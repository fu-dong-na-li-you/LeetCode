#include "iostream"
using namespace std;
#include "vector"

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> res;
	int low = 1, high = 2, curSum = 1;
	while (low < high)
	{
		curSum = curSum + high;   //CurSum�ۻ�ֵ������high�����Ӷ����ӣ����ջᳬ��sum
		high++;
		while (curSum > sum)
		{
			curSum = curSum - low;  //��CurSum����sum����𽥼�ȥlow�����ջ����sum
			low++;
		}

		if (curSum == sum && low != high - 1)  //�����ҵ���sum��ȵ�ֵ, ͬʱlow��high����Ϊͬһ��ֵ
		{
			vector<int> tmp;
			for (int i = low; i < high; i++)
			{
				tmp.push_back(i);
			}
			res.push_back(tmp);
		}
		return res;
	}

}