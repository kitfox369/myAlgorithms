#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N = 0,count=0;
	//에라스토테네스의 체를 이용
	int* array = new int[1000001] {0,1 };		//1은 소수가 아니기 때문
	//2의 배수,3의 배수....에 1 값을 넣음
	while (1) {
		count = 0;
		scanf("%d", &N);
		if (N == 0) break;
		for (int i = 2; i <= 2 * N; i++) array[i] = 0;
		for (int i = 2; i <= 2*N; i++) {
			for (int j = 2; i * j <=2*N; j++) {
				array[i * j] = 1;
			}
		}

		for (int i = N+1; i <= 2 * N; i++)
			if (array[i] == 0) count++;

		printf("%d\n", count);
	}


	return 0;
}