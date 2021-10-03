#include<iostream>
#include<algorithm>
using namespace std;

// 2156번 포도주 시식

int N,result;
int a[10001];
int dp[10001];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + a[i]) {
			dp[i] = dp[i - 2] + a[i];
		}
		if (dp[i] < dp[i - 3] + a[i - 1] + a[i]) {
			dp[i] = dp[i - 3] + a[i - 1] + a[i];
		}
	}

	cout << dp[N];

	return 0;
}