#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 10816번 숫자 카드 2

vector<long long> arr;
vector<long long>checkArr;

//해당 배열 값 중 원하는 값이 처음으로 나타나는 배열의 위치
int getLowerNum(int num,int size) {
	int start = 0, end = size - 1,mid=0;

	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] >= num)
			end = mid;
		else start = mid + 1;
	}

	return end;
}

//해당 배열 값 중 원하는 값보다 큰값이 처음으로 나타나는 위치
int getUpperNum(int num,int size) {
	int start = 0, end = size - 1, mid = 0;

	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] > num)
			end = mid;
		else start = mid + 1;
	}

	return end;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,M;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	//분할 정복을 하기 위해서 오름차순 sorting이 필요함
	sort(arr.begin(), arr.begin() + arr.size());

	cin >> M;

	for (int i = 0; i < M; i++) {
		long long num;
		cin >> num;
		checkArr.push_back(num);
	}

	
	for (int i = 0; i < M; i++) {
		
		int upper = getUpperNum(checkArr[i], N);
		int lower = getLowerNum(checkArr[i], N);
        
		if (upper == N - 1 && arr[N - 1] == checkArr[i]){
			upper++;
        }				

		cout << upper-lower<<" ";

	}

	return 0;
}