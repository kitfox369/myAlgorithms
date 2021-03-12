#include<iostream>
using namespace std;

int main() {
	int N=0,count=0;

	scanf("%d", &N);
	int* arrayX = new int[N] {0,};
	int* arrayY = new int[N] {0, };
	//입력 받기
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arrayX[i], &arrayY[i]);
	}
	//비교하기
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			if (arrayX[i] < arrayX[j] && arrayY[i] < arrayY[j])
				count++;
		}
		printf("%d ", count);
	}
	

	return 0;
}