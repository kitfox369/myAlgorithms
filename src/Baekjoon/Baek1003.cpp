#include <iostream>

using namespace std;

//1003번 피보나치 함수
int dp[41] = { 0,1 };

int main() {

	int T;
	cin >> T;

	for (int n = 2; n <= 40; n++) dp[n] = dp[n - 1] + dp[n - 2];

	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 0)
			printf("1 0\n");
		else if (N == 1)
			printf("0 1\n");
		else
		{
			printf("%d %d\n",dp[N-1],dp[N]);
		}
	}

}