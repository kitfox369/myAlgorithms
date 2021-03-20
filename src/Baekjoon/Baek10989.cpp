//https://sihyungyou.github.io/baekjoon-10989/ 참고
#include <iostream>

int C[10001] = { 0, };
int main() {

	int N, temp, max=0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		C[temp]++;			//몇개인지 입력 받을 때 미리 계산
		if (temp > max)		//max가 temp보다 작으면 갱신해줌
			max = temp;
	}

	for (int i = 0; i <= max; i++) {		//max만큼만 배열 출력
		for (int j = 0; j < C[i]; j++)		//배열의 갯수만큼 출력
			printf("%d\n", i);
	}

	return 0;
}