#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int M=0,N=0,sum=0,first=0;
	
	scanf("%d", &M);
	scanf("%d", &N);
    
    //1번부터 제곱수를 돌려서 범위안에 드는 것을 찾는 것이 나을 것 같음
    //나의 알고리즘은 1의 예외처리 필수
	if ((int)sqrt(N) - (int)sqrt(M) >= 1||M==1) {
		if (M != 1)
			first = (int)sqrt(M) + 1;
		else
			first = 1;
		for (int i = first; i <= sqrt(N); i++) {
			sum += i * i;
		}
		first *= first;
		printf("%d\n%d", sum, first);
	}
	else {
		printf("-1");
	}

	return 0;
}