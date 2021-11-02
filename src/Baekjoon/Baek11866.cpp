#include<iostream>
#include<string>
#include<queue>
using namespace std;

// 11866번 요세푸스 문제 0

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<int> st;
	queue<int>tempQ;

	int N,K, temp = 0;
	string str;
	cin >> N>>K;

	for (int i = 1; i <= N; i++) {
		//숫자만큼 입력
		st.push(i);
	}

	cout << "<";
	while (st.size() > 0) {
		//앞의 K-1개의 숫자를 큐의 뒷로 다시 삽입
		for (int i = 0; i < K-1; i++) {
			st.push(st.front());
			st.pop();
		}
		//K번째 수를 결과로 출력
		cout << st.front();
		st.pop();

		if (st.size()>0)cout<< ", ";
	}
	cout << ">";

	return 0;
}