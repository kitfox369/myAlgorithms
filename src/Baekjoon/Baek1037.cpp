#include<iostream>
#include<algorithm>
using namespace std;

// 1037번 약수

int main() {

	int realN;		//진짜 약수 갯수

	cin >> realN;
	//realN 만큼 int 배열 할당
	int* arr = new int[realN];

	for (int i = 0; i < realN; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + realN);

	//N은 제일 작은 약수와 제일 큰 약수의 곱임
	cout << arr[0] * arr[realN - 1];

	return 0;
}