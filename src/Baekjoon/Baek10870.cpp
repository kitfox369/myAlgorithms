#include<iostream>
#include<cmath>
using namespace std;

int fibo(int num) {
	if (num == 0) return 0;
	else if (num == 1) return 1;
	else return fibo(num - 1) + fibo(num - 2);		//재귀함수 사용
}

int main() {
	int N = 0;

	scanf("%d", &N);
	printf("%d", fibo(N));

	return 0;
}