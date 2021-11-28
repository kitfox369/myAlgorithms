#include<iostream>
#include<queue>
using namespace std;

// 11279번 최대힙

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	priority_queue<int> priorQ;

	cin >> N;

	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		if (temp == 0) {
			//0을 입력받을 때 
			if (priorQ.empty())
				cout << "0\n";
			else {
				//사이즈가 0보다 더 클 경우 최대 수 삭제
				cout << priorQ.top() << "\n";
				priorQ.pop();
			}
		}
		else {
			priorQ.push(temp);
		}
	}

	return 0;
}