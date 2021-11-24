#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1026번 보물

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> A;
	vector<int> B;
	int N,sum=0;

	cin >> N;

	int temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	//A는 오름차순으로 정렬
	sort(A.begin(), A.end());
	//B는 내림차순으로 정렬
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < N; i++) {
		//계산
		sum += (A[i] * B[i]);
	}

	cout << sum;

	return 0;
}