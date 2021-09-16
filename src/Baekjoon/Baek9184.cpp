#include <iostream>

using namespace std;

//9184번 신나는 함수 실행
int a, b, c;
int dp[21][21][21];

//dp(dynamic programming)를 이용한 wFuc함수
//최적화 기법 중 하나로 재귀를 이용하여 최적화 솔루션을 얻어내는 방식 사용
int wFuc(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return wFuc(20, 20, 20);
	else if (a < b && b < c) {
		if (dp[a][b][c] != 0) return dp[a][b][c];
		else return dp[a][b][c]=wFuc(a, b, c - 1) + wFuc(a, b - 1, c - 1) - wFuc(a, b - 1, c);
	}
	else {
		if (dp[a][b][c] != 0) return dp[a][b][c];
		else return dp[a][b][c]=wFuc(a - 1, b, c) + wFuc(a - 1, b - 1, c) + wFuc(a - 1, b, c - 1) - wFuc(a - 1, b - 1, c - 1);
	}
}

int main() {
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w("<<a<<", "<<b<<", "<<c<<") = "<<wFuc(a,b,c)<<endl;
	}
	
}