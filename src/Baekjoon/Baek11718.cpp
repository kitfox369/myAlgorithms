#include<iostream>
#include<string>
using namespace std;

// 11718번 그대로 출력하기

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;

	while (1) {
		getline(cin, str);
        //만약 입력받은게 공백이면
		if (str.length()<1)
			break;
		cout << str<<"\n";
	}

	return 0;
}