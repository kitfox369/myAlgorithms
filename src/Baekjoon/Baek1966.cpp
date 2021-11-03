#include<iostream>
#include<string>
#include<queue>
using namespace std;

// 1966번 프린터 큐
// to do : 우선 순위 큐를 구현해볼 것

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,M,t, temp = 0,count;
	cin >> t;

	for (int i = 0; i < t; i++) {
		count = 0;
		queue<pair<int, int>> qu;
		priority_queue<int> priorityQ;
		cin >> N >> M;

		for (int j = 0; j < N; j++) {
			cin >> temp;
			qu.push({ j,temp });
			priorityQ.push(temp);
		}

		while (qu.size() > 0) {
			int idx = qu.front().first;
			int val = qu.front().second;
			qu.pop();

			if (priorityQ.top() == val) {
				priorityQ.pop();
				count++;
				if (idx == M) {
					cout << count << "\n";
					break;
				}
			}
			else {
				qu.push({ idx,val });
			}
		}
	}

	return 0;
}