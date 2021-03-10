#include<iostream>
using namespace std;

int main() {
	int N=0,M=0,sum=0,max=0;

	scanf("%d %d", &N,&M);
	int* array = new int[N] {0,};
	//입력 받기
	for (int i = 0; i < N; i++) {
		scanf("%d",&array[i]);
	}
	//경우의 수 계산(앞에서부터 3개씩 계산)
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int z = j + 1; z < N; z++) {
				sum = array[i] + array[j] + array[z];
				if (sum > max && sum <= M)
					max = sum;
			}
		}
	}
	printf("%d", max);

	return 0;
}