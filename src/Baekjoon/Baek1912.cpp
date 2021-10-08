#include<iostream>
#include<algorithm>
using namespace std;

// 2579번 계단 오르기

int n;
int arr[100001];
int dp[100001];

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	int maxSum = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		if (dp[i] > maxSum) {
			maxSum = dp[i];
		}
	}

	cout << maxSum;

	return 0;
}