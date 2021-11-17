#include<iostream>
using namespace std;

// 1654번 랜선 자르기
// 참고 및 인용 : https://cocoon1787.tistory.com/288

int line[10001];
int  maxi = 0;
long long mid, high, low;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int K, N;

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		if (maxi < line[i]) maxi = line[i];
	}
	low = 1;
	high = maxi;
	int ans = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += line[i] / mid;

		if (cnt >= N) {			//만약 전선수가 만들어야하는 전선수보다 크거나 같을 때
			low = mid + 1;
			if (ans < mid) ans = mid;
		}
		else {						//만약 전선수가 만들어야하는 전선수보다 크거나 작을 때
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}