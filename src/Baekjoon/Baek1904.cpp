#include <iostream>
#include<vector>
using namespace std;

//1904번 01타일

int N;
vector<long long> fiboArray = { 0,1,2 };

//피보나치 규칙성: 앞의 숫자와 뒤의 숫자의 합이 다음수가 됨
void fiboFunc() {
	long long temp;
	for (int i = 3; i <= N; i++) {
		temp = 0;
		temp = fiboArray[i - 1] + fiboArray[i - 2];
		fiboArray.push_back(temp % 15746);			//값도 나누어서 저장
	}
}

int main() {

	cin >> N;
	fiboFunc();		//피보나치 수열 계산
	cout << fiboArray[N] % 15746;		//출력할때 한번 더 확인

	return 0;
}