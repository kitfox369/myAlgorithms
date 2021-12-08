#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 10610번 30
// 30의 배수이기 위해서는 끝의 자리수가 0이여야하고 각 자리의 수 합이 3의 배수여야함

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string N;
	cin >> N;
	long long sum = 0;
	bool isZero = 0;
	for (int i = 0; i < N.size(); i++) {
		//자릿수 더하기
		sum += (N[i] - '0');
		if ((N[i] - '0') == 0) isZero = true;
	}

	if (sum % 3 || !isZero)
		cout << "-1\n";
	else {
		//내림차순으로 정렬
		sort(N.begin(), N.end(), greater<int>());
		cout << N << "\n";
	}


	return 0;
}