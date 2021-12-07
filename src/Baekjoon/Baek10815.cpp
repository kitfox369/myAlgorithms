#include<iostream>
#include<algorithm>
using namespace std;

// 10815번 숫자카드
// 이분 탐색을 사용하지 않고 순차 탐색시 시간 초과가 뜸

int arr[500001];
int N,M,temp,isExist=false;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	//이분 탐색을 위한 sorting
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		isExist = false;
		cin >> temp;
		//이분 탐색
		int left = 0, right = N - 1,mid=0;
		while (left <= right) {
			mid = (left + right) / 2;        //중간값 계산
			if (arr[mid] > temp) {
				right = mid - 1;
			}
			else if (arr[mid] < temp) {
				left = mid + 1;
			}
			else {
				//탐색 완료
				cout << "1 ";
				isExist = true;
				break;
			}
		}
		if (!isExist) cout << "0 ";
	}


	return 0;
}