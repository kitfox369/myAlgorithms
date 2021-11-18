#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2805번 나무 자르기
//참고 및 인용 : https://jaimemin.tistory.com/965

int N, M;
long long high;
vector<long long> arr;

bool possible(long long height)
{
	long long len = 0;

	//나무를 잘라본다
	for (int i = 0; i < N; i++)
		if (arr[i] - height > 0)
			len += arr[i] - height;

	//조건 충족
	if (len >= M)
		return true;

	return false;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>M;

	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		arr.push_back(temp);
		high = max(high, arr[i]);
	}

	//정렬하기
	sort(arr.begin(), arr.end());

	long long result = 0;
	long long left=0;
	while (left <= high)
	{
		long long mid = (left + high) / 2;
		if (possible(mid))
		{
			result = max(result, mid);
			left = mid + 1;
		}

		else
			high = mid - 1;
	}

	cout << result;

	return 0;
}