#include<iostream>
#include<string>
#include<deque>
using namespace std;

// 10866번 덱

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> st;

	int N, temp;
	string str;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push_back") {
			cin >> temp;
			st.push_back(temp);
		}
		else if (str == "push_front") {
			cin >> temp;
			st.push_front(temp);
		}
		else if (str == "front") {
			(st.size() > 0) ? cout << st.front() << "\n" : cout << "-1\n";
		}
		else if (str == "back") {
			(st.size() > 0) ? cout << st.back() << "\n" : cout << "-1\n";
		}
		else if (str == "pop_front") {
			if (st.size() > 0) {
				cout << st.front() << "\n";
				st.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back") {
			if (st.size() > 0) {
				cout << st.back() << "\n";
				st.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "empty") {
			(st.size() > 0) ? cout << "0\n" : cout << "1\n";
		}
		else if (str == "size") {
			cout << st.size() << "\n";
		}
	}

	return 0;
}