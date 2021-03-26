#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool compare(pair<int, string> self, pair<int, string> target) {		//const + & 사용시 틀림
	return self.first < target.first;
}

int main() {
	ios_base::sync_with_stdio(0);			//cin 사용시 시간 초과를 초래하기 때문에 사용
	cin.tie(0);

	int N;

	vector<pair<int, string>> arr;
	pair<int, string> temp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp.first>> temp.second;
		arr.push_back(temp);
	}

	stable_sort(arr.begin(), arr.end(), compare);		

	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";		//endl 사용시 시간 초과를 초래
	}

	return 0;
}