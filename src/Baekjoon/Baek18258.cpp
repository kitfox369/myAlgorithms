#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

// 18258번 큐2
// to do : 직접 링크드 리스트로 구조 만들어볼것

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<int> st;

	int N, temp;
	string str;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push") {
			cin >> temp;
			st.push(temp);
		}
		else if(str == "front") {
			(st.size() > 0)? cout << st.front()<<"\n":cout << "-1\n";
		}
		else if (str == "back") {
			(st.size() > 0) ? cout << st.back() << "\n" : cout << "-1\n";
		}
		else if (str == "pop") {
			if (st.size() > 0) {
				cout << st.front()<< "\n";
				st.pop();
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