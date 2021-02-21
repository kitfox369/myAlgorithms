#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int T = 0, x = 0,j=1;
	int count = 0;
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf_s("%d", &x);

		bool isPrime=true;

		for (j = 2; j < x; j++) {		//2부터 x까지 나누어 떨어지는 수가 있으면  소수 x
			if (x%j == 0) {
				break;
			}
		}
		if (j == x) {		//j가 x까지 검사 한 경우에 count
			count+=1;
		}
	}
	
	printf("%d", count);

	return 0;
}
