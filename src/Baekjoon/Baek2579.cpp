#include<iostream>
#include<algorithm>
using namespace std;

// 2579번 계단 오르기
int n;
int arr[301];
int dp[301];

int main() {
	cin >> n;
	//배열 입력받기
	for (int i = 0; i < n; i++)
		cin>>arr[i];

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0], arr[1]) + arr[2];

	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];

	cout << dp[n - 1];

	return 0;
}