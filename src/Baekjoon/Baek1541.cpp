#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// 1541번 잃어버린 괄호

int main() {
	
	string arr,tmp="";
	int num = 0;
	bool checkMinus=false;

	cin >> arr;

	for (int i = 0; i <= arr.size(); i++) {
		if (arr[i] == '+' || arr[i] == '-' || arr[i] == '\0') {
			if (checkMinus)			//처음 나온 연산자가 - 인 경우 
				num-= stoi(tmp);
			else             //반대 경우
				num += stoi(tmp);

			if (arr[i] == '-')
				checkMinus = true;

			tmp = "";
			continue;
		}
		tmp += arr[i];
	}

	cout << num;

	return 0;
}