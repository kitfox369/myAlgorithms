#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1920번 수 찾기

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,M;
	vector<int> arr;
	vector<int>checkArr;
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
		int num;
		cin >> num;
		checkArr.push_back(num);
	}
	int mid;
	
	for (int i = 0; i < M; i++) {
		int left = 0, right = N - 1;
		bool isIn = false;
        //분할 정복
		while (left <= right) {
			mid = (left + right) / 2;		//중간값
			if (arr[mid] > checkArr[i]) {
				right = mid - 1;
			}
			else if (arr[mid] < checkArr[i]) {
				left = mid + 1;
			}
			else {
				isIn = true;        //값을 찾을 경우
				break;
			}
		}
		cout << isIn << "\n";
	}

	return 0;
}