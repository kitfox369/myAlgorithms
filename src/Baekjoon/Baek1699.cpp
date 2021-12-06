#include<iostream>
using namespace std;

// 1699번 제곱수의 합

int arr[1000000];
int n;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (arr[i] > arr[i - j * j] + 1)
				arr[i] = arr[i - j * j] + 1;
		}
	}

	cout << arr[n];

	return 0;
}