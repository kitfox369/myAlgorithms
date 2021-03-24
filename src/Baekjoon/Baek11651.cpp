#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(const pair<int, int>&self , const pair<int, int>& target) {
	//비교하는 수 self의 second가 비교하는 target second보다 작을 때, sort함
	if (self.second < target.second)	return true;		
	else if (self.second == target.second) return self.first < target.first;		//second가 같을 때 first로 비교
	else return false;		
}

int main() {
	
	int N;
	vector<pair<int, int>> arr;

	scanf_s("%d", &N);
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr.begin(), arr.end(),compare);		//pair를 sort하면 second값까지 고려해서 sort해주는 함수로 작동됨

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", arr[i].first, arr[i].second);
	}

	return 0;
}