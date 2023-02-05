#include<iostream>

using namespace std;

int main() {

	//영수증의 총액 X
	int X;
	cin >> X;
	//구매한 물건의 종류 수 N
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}

	(sum == X) ? cout << "Yes" : cout << "No";

	return 0;
}