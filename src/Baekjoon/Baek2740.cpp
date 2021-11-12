#include<iostream>
using namespace std;

// 2740번 행렬 곱셈

int A[101][101];	//A 행렬 B 행렬
int B[101][101];
int result[101][101];
int N, M,K;

//분할 정복 : 슈트라센 알고리즘 사용
void strassenAlgorithm() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int z = 0; z < M; z++) {
				result[i][j] += A[i][z] * B[z][j];
			}
			cout<<result[i][j]<<" ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//2개의 행렬을 받음
	//A 행렬 받기
	cin >> N >> M;		//N by M 행렬 입력 받기
	for (int i = 0;i< N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	//B 행렬 받기
	cin >> M >> K;		//N by M 행렬 입력 받기
	for (int i = 0;i< M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}

	strassenAlgorithm();

	return 0;
}

