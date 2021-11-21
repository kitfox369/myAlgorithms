#include<iostream>
using namespace std;

// 2748번 피보나치 수 2

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int num = 0;
	
	long long arr[91] = { 0,1 };

	cin >> n;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	cout << arr[n];

	return 0;
}