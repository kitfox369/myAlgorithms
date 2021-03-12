#include<iostream>
using namespace std;

int main() {
	int N = 0, sum = 0, num = 0,i=0;

	scanf("%d", &N);
	num = N;
	//1부터 N까지 검사해봄
	for (i = 1; i < N; i++) {
		sum = i;
		num = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum == N) {
			printf("%d", i);
			return 0;
		}	
	}
    //만약 for 문이 끝난 후에 sum!=N인 경우(생성자가 없는 경우)
	printf("0");

	return 0;
}