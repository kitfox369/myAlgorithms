#include<iostream>
using namespace std;

// 1629번 곱셈

//분할 정복을 통한 시간 감소
long long splitPow(long long A, long long B, long long C) {

	if (B == 0)		return 1;		//만약 곱하는 횟수가 1이면

	long long temp = splitPow(A, B / 2, C);
	temp = temp * temp%C;

	if (B % 2 == 0)	return temp;		//만약 짝수번 곱한다면 분할정복을 할 시 나머지가 없기 때문에 그냥 return
	else return (temp*A) % C;		//홀수번 곱한다면 분할정복 할 시 나머지가 한번 생기기 때문에 A를 한번 더 곱하고 C로 다시 나머지로 return

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long A, B, C,sum=1;

	cin >> A >> B >> C;

	sum = splitPow(A, B, C);
	cout << sum;

	return 0;
}

