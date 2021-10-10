#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1931번 회의실 배정

int main() {
	
	int N, end, begin;
	int value[10];
	vector<pair<int, int>> schedule;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin));
	}

	sort(schedule.begin(),schedule.end());

	int time = schedule[0].first;
	int count = 1;
	
	for (int i = 1; i < N; i++) {
		if (time <= schedule[i].second) {
			count++;
			time = schedule[i].first;
		}
	}

	cout << count;

	return 0;
}