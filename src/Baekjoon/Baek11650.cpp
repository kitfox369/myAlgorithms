#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	
	int N;
	vector<pair<int, int>> arr;

	scanf("%d", &N);
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr.begin(), arr.end());		//pair를 sort하면 second값까지 고려해서 sort해주는 함수로 작동됨

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", arr[i].first, arr[i].second);
	}

	return 0;
}