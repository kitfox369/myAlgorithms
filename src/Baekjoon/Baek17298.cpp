#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// 17298번 오큰수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> V(N), ret(N);			//V: 입력받은 수열, ret : 결과 수열
	stack<int> stk;

	for (int i = 0; i < N; i++)
		cin >> V[i];

	for (int i = N - 1; i >= 0; i--) {
		while (!stk.empty() && stk.top() <= V[i])			//stk가 비어있지 않고 제일 뒤의 숫자가 해당 숫자보다 작으면 제외
			stk.pop();

		if (stk.empty())
			ret[i] = -1;
		else
			ret[i] = stk.top();

		stk.push(V[i]);			//다시 스택 채우기
	}

	for (int i=0;i<N;i++)
		cout << ret[i] << " ";

	return 0;
}