#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2110번 공유기 설치

int N, C;

vector<long long> arr;

bool possible(long long distance)
{
	long long len = 1,prev=arr[0];

	for (int i = 0; i < N; i++) {
		//만약 i번째 집에서 prev집까지의 거리가 현재 탐색의 중간값보가 높으면
		if (arr[i] - prev >= distance) {
			len++;
			prev = arr[i];
		}
	}
	if (len >= C)
		return true;

	return false;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>C;

	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		arr.push_back(temp);
	}

	//정렬하기
	sort(arr.begin(), arr.end());

	long long result = 0;
	long long left=1, right = arr[N-1]-arr[0];
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (possible(mid))
		{
			result = max(result, mid);
			left = mid + 1;
		}

		else
			right = mid - 1;
	}

	cout << result;

	return 0;
}