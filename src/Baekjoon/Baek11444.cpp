#include<iostream>
#include<vector>
using namespace std;

// 11444번 피보나치 수 6
//참고 및 인용 : https://cocoon1787.tistory.com/349

//피사노 주기를 사용, 피보나치의 점화식 사용
//피보나치 수열 Fn = Fn-1 + Fn-2
vector<vector<long long>> fibo(vector<vector<long long>>& a,vector<vector<long long>>& b) {
	
	vector<vector<long long>> tVec(2, vector<long long>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				tVec[i][j] += a[i][k] * b[k][j];

			tVec[i][j] %= 1000000007;
		}
	}

	return tVec;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;

	vector<vector<long long>> ans = { {1,0},{0,1} };
	vector<vector<long long>> matrixTemp = { {1,1},{1,0} };

	cin >> n;

	while (n > 0) {

		if (n % 2 == 1) {
			ans = fibo(ans, matrixTemp);
		}
		matrixTemp = fibo(matrixTemp, matrixTemp);

		n /= 2;
	}

	cout << ans[0][1];

	return 0;
}

