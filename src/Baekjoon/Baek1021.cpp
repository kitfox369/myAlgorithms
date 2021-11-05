#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

// 1021번 회전하는 큐

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> st;

	int N,M, temp=0,count=0,idx;
	string str;
	cin >> N>>M;

	for (int i = 1; i <= N; i++) {
		st.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;

		for (int j = 0; j < st.size(); j++) {
			if (st[j] == temp) {
				idx = j;
				break;
			}
		}

		if (idx < st.size() - idx) {
			while (1) {
				if (st.front() == temp) {
					st.pop_front();
					break;
				}
				count++;
				st.push_back(st.front());
				st.pop_front();
			}
		}
		else {
			while (1) {
				if (st.front() == temp) {
					st.pop_front();
					break;
				}
				count++;
				st.push_front(st.back());
				st.pop_back();
			}
		}
	}
	
	cout << count;

	return 0;
}