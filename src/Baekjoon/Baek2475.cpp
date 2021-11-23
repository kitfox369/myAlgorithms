#include<iostream>

using namespace std;

// 2475번 검증수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	int powNum = 0;

	for (int i = 0; i < 5; i++) {
		powNum = 0;
		int temp;
		cin >> temp;
		powNum = temp * temp;
		sum += powNum;
	}

	cout << sum % 10;

	return 0;
}