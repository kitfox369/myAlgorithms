#include<iostream>
using namespace std;

// 11401번 이항 계수 3

int MOD = 1000000007;
long long N, K,halfNum,A,B;

// 이항 계수 : (N,K) = (N!)/K!(N-K)!
// 페르마의 소정리 이용
long long getBinaryCoefficient(long long N) {
	if (N == 0)		return 1;

	if (N % 2 == 1) return B * getBinaryCoefficient(N - 1) % MOD;		//두개로 나누어서 진행
	else {
		halfNum = getBinaryCoefficient(N / 2);
		return halfNum * halfNum% MOD;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>K;

	A = 1;
	B = 1;

	for (int i = N; i >= N - K + 1; i--) {
		A = (A*i) % MOD;
	}

	for (int i = 1; i <= K; i++) {
		B = (B*i) % MOD;
	}

	B = getBinaryCoefficient(MOD -2);

	cout << A * B%MOD;

	return 0;
}