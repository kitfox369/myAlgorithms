#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 2004번 조합 0의 개수
// 코드 인용 : https://j3sung.tistory.com/235

//a에 대한 b의 소인수 갯수 출력
long long getPrimeFactorNum(int a, int b) {
	int num = 0;

	for (long long i = b; a / i >= 1; i *= b) {
		num += a / i;
	}

	return num;
}

int main() {

	int n, m;

	cin >> n >> m;

	long long five = 0;
	long long two = 0;

	five = getPrimeFactorNum(n, 5) - getPrimeFactorNum(n - m, 5) - getPrimeFactorNum(m, 5);
	two = getPrimeFactorNum(n, 2) - getPrimeFactorNum(n - m, 2) - getPrimeFactorNum(m, 2);

	cout << min(five, two);
	
	return 0;
}