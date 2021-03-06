#include<iostream>
using namespace std;

int main() {
	int N=0,sum=1;
	
	scanf("%d", &N);

	if (N > 0) {
		while (N > 0) {
			sum *= N;
			N--;
		}
		printf("%d",sum);
	}
	else
		printf("1");

	return 0;
}