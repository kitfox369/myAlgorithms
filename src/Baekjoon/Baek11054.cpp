#include<iostream>
#include<algorithm>
using namespace std;

// 11054번 가장 긴 바이토닉 부분 수열

int N,maxNum;
int A[1001];
int dp[2][1001];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		dp[0][i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dp[0][i] < dp[0][j] + 1)
				dp[0][i] = dp[0][j] + 1;
		}
	}

	for (int i = N-1; i >= 0; i--) {
		dp[1][i] = 1;
		for (int j = N-1; j >= i; j--) {
			if (A[i] > A[j] && dp[1][i]<dp[1][j] + 1)
				dp[1][i] = dp[1][j] + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		if (maxNum < dp[0][i] + dp[1][i] - 1)
			maxNum = dp[0][i] + dp[1][i] - 1;
	}

	cout << maxNum;

	return 0;
}