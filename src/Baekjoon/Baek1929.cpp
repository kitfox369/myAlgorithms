#include<iostream>
#include<vector>
using namespace std;

int main() {
	int M = 0, N = 0;
	scanf("%d %d", &M,&N);
	//에라스토테네스의 체를 이용
	int* array = new int[1000001] {0,1 };		//1은 소수가 아니기 때문
	//2의 배수,3의 배수....에 1 값을 넣음
	for (int i = 2; i <= N; i++) {
		for (int j = 2; i*j <= N; j++) {
			array[i * j] = 1;
		}
	}

	for (int i = M; i <= N; i++)
		if (array[i]==0) printf("%d\n", i);

	return 0;
}