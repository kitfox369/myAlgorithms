#include<iostream>
using namespace std;

int main() {
	int N=0,K=0,sum=0;

	scanf("%d %d",&N, &K);
	int* cInput = new int[N]{ 0, };
	//N만큼의 동전 입력
	for (int i = 0; i < N; i++) {
		scanf("%d", &cInput[i]);
	}
    //동전 세기
	for (int i = N-1; i >= 0; i--) {
		if (K == 0) break;
		if (cInput[i] > K) continue;
		sum += K / cInput[i];
		K %= cInput[i];
	}

	printf("%d", sum);

	return 0;
}