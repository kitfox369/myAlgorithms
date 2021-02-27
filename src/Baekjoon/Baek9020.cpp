#include<iostream>
using namespace std;

int main() {
	int N = 0, count = 0;
	
	int* array = new int[10001]{ 0,1 };		//1은 소수가 아니기 때문
	//에라스토테네스의 체를 이용
	for (int i = 2; i <= 10001; i++) {
		for (int j = 2; i * j <= 10001; j++) {
			array[i * j] = 1;
		}
	}
	
	scanf("%d", &count);

	while (count--) {
		scanf("%d", &N);
		//최소값과 최댓값에서 소수인경우 점점 중간 지점에서 만나도록
		for (int i = N / 2; i > 0; i--) {
			if (array[i] == 0 && array[N - i] == 0) {
				printf("%d %d\n", i, N - i);
				break;
			}
		}
	}

	return 0;
}