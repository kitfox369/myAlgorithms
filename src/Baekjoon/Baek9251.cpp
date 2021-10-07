#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 2579번 계단 오르기
int n;
string st1, st2;
int dp[1001][1001];

int main() {
	//string으로 배열 받기
	cin >> st1 >> st2;

	int st1Size = st1.size();
	int st2Size = st2.size();

	for (int i = 1; i <= st2Size; i++) {
		for (int j = 1; j <= st1Size; j++) {
			if (st2[i - 1] == st1[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[st2Size][st1Size];

	return 0;
}