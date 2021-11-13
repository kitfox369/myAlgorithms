#include<iostream>
using namespace std;

// 2740번 행렬 곱셈

long long A[5][5];	//A 행렬 B 행렬
long long X[5][5];
long long result[5][5];
long long N,B;

//제곱
void squareMatrix(long long a[5][5], long long x[5][5]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[i][j] = 0;
			for (int z = 0; z < N; z++) {
				result[i][j] += (a[i][z] * x[z][j]);
			}
			result[i][j]%=1000;
		}
	}
	//계산 값 대입
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = result[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//2개의 행렬을 받음
	//A 행렬 받기
	cin >> N >> B;		//N by N 행렬 입력 받기
	for (int i = 0;i< N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
		X[i][i] = 1;		//단위행렬로 초기화
	}

	//2개로 나누어서 진행
	while (B > 0)
	{
		if (B % 2 == 1)		//제곱 횟수가 홀수인 경우 한번 남는 연산을 해줌
		{
			squareMatrix(X, A); // 단위행렬, A행렬 곱하기
		}
		squareMatrix(A, A);
		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << X[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}