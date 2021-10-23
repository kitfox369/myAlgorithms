#include<iostream>
#include<algorithm>
using namespace std;

// 2981번 검문
// 코드 인용 : https://defian.tistory.com/57

int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	return gcd(b, a%b);
}

int main() {

	int n,num,cnt=0;
	int arr[101] = { 0, };
	int sol[501] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	//arr[i]-arr[i-1]의 최대공약수 구하기
	int bm = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		bm = gcd(bm, arr[i] - arr[i - 1]);
	}

	//나눗셈을 이용하여서 한개의 약수를 알면 그 짝을 바로 구함
	for (int i = 2; i*i <= bm; i++) {
		if (bm%i == 0) {
			sol[cnt++] = i;
			if (i*i != bm)	sol[cnt++] = bm / i;
		}
	}
	//1의 짝을 마지막 자리에 삽입
	sol[cnt++] = bm;

	sort(sol, sol + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << sol[i]<<" ";
	}

	return 0;
}