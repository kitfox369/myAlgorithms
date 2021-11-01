#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

// 2164번 카드2

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<int> st;

	int N, temp=0;
	string str;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		//숫자만큼 입력
		st.push(i);
	}

	while(st.size()>1){
		//제일 위의 것을 버림
		st.pop();
		if (st.size() > 0) {
			temp = st.front();
			st.pop();
			st.push(temp);
		}
	}

	cout << st.front();

	return 0;
}