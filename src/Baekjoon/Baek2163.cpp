#include<iostream>
using namespace std;

// 2163번 초콜릿 자르기

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	//N x M  크기의 초콜릿 하나 가짐
	int N, M;
	cin >> N >> M;

	//쪼개는 횟수는 N*(M-1)+(N-1)
	cout << N * (M - 1) + (N - 1);


	return 0;
}