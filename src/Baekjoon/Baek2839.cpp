#include<iostream>
#include<string>
using namespace std;

int main() {
	int T = 0, k = 5, n = 3;
	int bongjiNum=0;
	scanf("%d", &T);
	while (T > 0) {		//우선순위 설정
		if (T%k == 0) {		//5로 나누어지는 경우(이 경우가 제일 적은 경우의 수)
			T -= k;
			bongjiNum++;
		}
		else if (T%n == 0) { //3으로 나누어지는 경우
			T -= n;
			bongjiNum++;
		}
		else if (T > k) {		//5와3으로 나누어지지 않을때 5보다 크면 빼고 더함
			T -= k;				//3보다 큰 경우에는 무조건 봉지수가 많아지기 때문에 계산X
			bongjiNum++;
		}
		else {
			bongjiNum = -1;
			break;
		}
	}
	printf("%d", bongjiNum);
	return 0;
}