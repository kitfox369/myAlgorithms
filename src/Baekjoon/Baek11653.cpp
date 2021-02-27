#include<iostream>
using namespace std;

int main() {
	int N = 0,  idx=2;

	scanf("%d", &N);
	while (N != 1) {
		if (N % idx == 0) {
			printf("%d\n", idx);
			N /= idx;
			idx = 2;
		}
		else {
			idx++;
		}
	}

	return 0;
}