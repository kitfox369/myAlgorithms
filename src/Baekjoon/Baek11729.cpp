#include<iostream>
#include<cmath>
using namespace std;
//from : 시작 지점 by : 중간 지점 to : 종착 지점
void recursiveHanoi(int n,int from,int by,int to) {
	if (n == 1)
		printf("%d %d\n", from, to);
	else {
		recursiveHanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		recursiveHanoi(n - 1, by, from, to);
	}
}
//참고 하노이탑 : https://ko.wikipedia.org/wiki/%ED%95%98%EB%85%B8%EC%9D%B4%EC%9D%98_%ED%83%91
int main() {
	int N = 0,count=0;

	scanf("%d", &N);
	count = pow(2, N) - 1;
	printf("%d\n", count);
	recursiveHanoi(N, 1, 2, 3);

	return 0;
}