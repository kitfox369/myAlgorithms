#include<iostream>
#include<string>
#include<vector>
using namespace std;

int factorialFunc(int k,int n);

int main() {
	int T = 0, k = 0, n = 0;
	vector<int> peopleNum;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &k);
		scanf("%d", &n);

		int num = factorialFunc(k,n);
		peopleNum.push_back(num);
	}
	for (int i = 0; i < peopleNum.size(); i++) {
		printf("%d\n", peopleNum[i]);
	}
	return 0;
}

int factorialFunc(int k,int n) {
	if (n == 1)return 1;
	if (k == 0) return n;
	return factorialFunc (k-1,n)+ factorialFunc(k,n-1);
}
