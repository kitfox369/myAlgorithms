#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

// 2217번 로프

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[100001];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N,greater<int>());

	long long result=0, sum = 0;
	for (int i = 0; i < N; i++) {
		sum = arr[i] * (i + 1);
		if (sum > result)
			result = sum;
	}

	cout << result;

	return 0;
}