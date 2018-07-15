#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main_huawei(){

	vector<int> input;
	string str;

	cin >> str;


	int pre = 0;
	for (int i = 0; i < str.size(); i++){
		string temp;

		if (i == str.size() - 1){
			temp = str.substr(pre);
			int k = atoi(temp.c_str());
			//cout << k << endl;
			input.push_back(k);

		}
		else if (str[i] == ','){
			temp = str.substr(pre, i);
			cout << temp << "     ";
			int k = atoi(temp.c_str() + 1);
			cout << k << endl;
			input.push_back(k);
			pre = i + 1;
		}
	}

	int currSum = input[0];
	int maxSum = input[0];

	for (int i = 1; i < input.size(); i++){

		currSum += input[i];
		if (currSum < input[i]){
			currSum = input[i];
		}
		if (currSum > maxSum){
			maxSum = currSum;
		}
	}
	cout << maxSum;

	system("pause");
	return 0;
}