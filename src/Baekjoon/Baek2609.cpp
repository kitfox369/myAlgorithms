#include<iostream>
using namespace std;

// 2609번 최대공약수와 최소공배수

//A*B = 최대공약수(GCD)*최소공배수(LCM)
int LeastCommonMultiple(int gcf,int a, int b) {
	return (a*b) / gcf;
}

//유클리드 호제법
int GreatestCommonFactor(int a,int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {

	int A, B;
	cin >> A >> B;

	int gcf = GreatestCommonFactor(A, B);
	//최대공약수
	cout << gcf <<"\n";
	//최소공배수
	int lcm = LeastCommonMultiple(gcf, A, B);
	cout << lcm;

	return 0;
}