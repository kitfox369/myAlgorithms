#include<iostream>

using namespace std;

// 1676번 팩토리얼 0의 개수

int main() {

	int n,num=0;

	cin >> n;

	for (int i = 5; i <= n; i *= 5) {
		num += n / i;
	}

	cout << num;

	return 0;
}