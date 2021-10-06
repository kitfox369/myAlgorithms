#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2565번 전깃줄

int N,maxNum;
int A[101];
int dp[1010];
pair<int, int> ar[101];

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ar[i].first >> ar[i].second;
	}

	sort(ar, ar + N);
	
	int res = -1;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if (ar[j].second < ar[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
			res = max(res, dp[i]);
		}
	}

	cout << N - res;

	return 0;
}