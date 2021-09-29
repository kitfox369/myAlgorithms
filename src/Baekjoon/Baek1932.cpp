#include<iostream>
#include<algorithm>
using namespace std;

// 1932번 정수 삼각형
int n, temp, maxNum = 0;
int dp[501][501] = { {0,0}, };

int main() {

	cin >> n;
	//입력 받기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> temp;
			dp[i][j] = temp;
		}
	}

	//계산
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) dp[i][j] += dp[i-1][j];	//왼쪽 대각선 경로
			else if (j == n) dp[i][j] += dp[i - 1][j - 1];		//오른쪽 대각선 경로
			else
				dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}

	//마지막 줄의 max 값을 찾음
	for (int i = 0; i <= n; i++) {
		maxNum = max(maxNum, dp[n][i]);
	}

	cout << maxNum;

}