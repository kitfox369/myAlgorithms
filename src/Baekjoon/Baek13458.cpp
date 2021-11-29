#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 13458번 시험 감독

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,B,C;
	long long sum = 0;
	vector<int> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		arr[i] -= B;
		sum++;
		if (arr[i] > 0) {
			if (arr[i] % C == 0)		sum += arr[i] / C;
			else		sum += (arr[i] / C) + 1;
		}
	}

	cout << sum;

	return 0;
}