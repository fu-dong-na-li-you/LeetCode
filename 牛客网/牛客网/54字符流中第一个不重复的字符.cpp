#include "iostream"
using namespace std;
#include "queue"

class solution54
{
public:
	
	void Insert(char ch)
	{
		++hash[ch - '\0'];
		if (hash[ch - '\0'] == 1)  //Ϊʲô�ַ�Ҳ�����½Ǳꣿ
		{
			data.push(ch); //�õ���push
		}

	}
	
	char FirstAppearingOnce()
	{
		while (!data.empty() && hash[data.front()] >= 2)  { data.pop(); }

		if (data.empty()) { return '#'; }

		return data.front();
	}
public:
	 queue<char>  data;     //
	 unsigned char hash[128];

};

void main54()
{
	system("pause");
}