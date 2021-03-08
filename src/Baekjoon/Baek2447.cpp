#include<iostream>
#include<cmath>
using namespace std;

void recursiveFunc(int i,int j,int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {		//중간에 있는줄
		printf(" ");
	}
	else {
		if (num / 3 == 0)
			printf("*");
		else
			recursiveFunc(i, j, num / 3);		//3씩 나누어 주면서 무늬를 작게 만듬
	}
}

int main() {
	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {		//가로
		for (int j = 0; j < N; j++) {	//세로
			recursiveFunc(i, j, N);
		}
		printf("\n");
	}

	return 0;
}