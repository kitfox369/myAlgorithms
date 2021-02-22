#include<iostream>
#include<string>
using namespace std;

int main() {
	int M = 0,N=0, min=0,j=1;
	int sum = 0;
	scanf("%d", &M);
	scanf("%d", &N);

	bool isCheck = false;
	//M~N까지 돌림
	for (int i = M; i <= N; i++) {
		for (j = 2; j < i; j++) {		//2부터 x까지 나누어 떨어지는 수가 있으면  소수 x
			if (i%j == 0) {
				break;
			}
		}

		if (j == i) {		//j가 x까지 검사 한 경우에 sum+=i
			sum += i;
			if (!isCheck) {
				min = i;
				isCheck = true;		//처음 체크 후 더이상 하지 않도록
			}
		}
	}
	
	if(sum!=0)
		printf("%d\n%d", sum,min);
	else
		printf("-1");

	return 0;
}
