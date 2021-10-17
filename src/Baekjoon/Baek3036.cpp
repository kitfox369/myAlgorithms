#include<iostream>
using namespace std;

// 3036번 링

//A*B = 최대공약수(GCD)*최소공배수(LCM)
int LeastCommonMultiple(int gcf, int a, int b) {
	return (a*b) / gcf;
}

//유클리드 호제법: 최대공약수
int GreatestCommonFactor(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {

	int T;
      int arr[1001];

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
       }

       int a=arr[0];
       for(int i=1;i<T;i++){
		//최대공약수
		int gcf = GreatestCommonFactor(a, arr[i]);

		
		cout << a/gcf << "/" << arr[i]/gcf <<"\n";
	}

	return 0;
}