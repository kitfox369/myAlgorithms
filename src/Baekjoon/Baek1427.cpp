#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main() {

	char arr[11];

	cin >> arr;
	//sort 함수를 이용하여 정렬 : 내림차순
	//greater<>()는 더 큰것을 비교해주는 임시객체
	//반대로 less<>()를 이용하여 오름차순 가능
	sort(arr, arr + strlen(arr), greater<int>());
	
	for (int i = 0; i < strlen(arr); i++)
		cout << arr[i];

	return 0;
}