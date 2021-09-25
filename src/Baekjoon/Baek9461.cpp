#include <iostream>
#include<vector>
using namespace std;

//9461번 파도반 수열

int N,T;
vector<long long> fiboArray = { 1,1,1,2,2 };

//파도반 수열의 규칙성은 0~4번까지는 1,1,1,2,2 로 같고 
//5번부터 a[i]=a[i-5]+a[i-1]의 성질을 띈다.
void padoFunc() {
	fiboArray.clear();
	fiboArray = { 1,1,1,2,2 };
	long long temp;
	for (int i = 5; i <= N; i++) {
		temp = 0;
		temp = fiboArray[i - 5] + fiboArray[i - 1];
		fiboArray.push_back(temp);
	}
}

int main() {

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		padoFunc();		//파도반 수열 계산
		cout << fiboArray[N-1]<<"\n";		
	}
	return 0;
}