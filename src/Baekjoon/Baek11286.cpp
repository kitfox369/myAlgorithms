#include<iostream>
#include<queue>
using namespace std;

// 11286번 절대값 힙

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	//양수는 최소힙으로 음수는 최대힙으로 저장
	priority_queue<int,vector<int>,greater<int>> priorQ;
	priority_queue<int> priorQUnder;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			//0을 입력받을 때 
			if (priorQ.empty()&&priorQUnder.empty())
				cout << "0\n";
			else {
				if (priorQ.empty()) {
					//사이즈가 0보다 더 클 경우 최소 수 삭제
					cout << priorQUnder.top() << "\n";
					priorQUnder.pop();
				}
				else if (priorQUnder.empty()) {
					//사이즈가 0보다 더 클 경우 최소 수 삭제
					cout << priorQ.top() << "\n";
					priorQ.pop();
				}
				else {
					if (priorQ.top() < -priorQUnder.top()) {
						cout << priorQ.top() << "\n";
						priorQ.pop();
					}
					else {
						cout << priorQUnder.top() << "\n";
						priorQUnder.pop();
					}
				}
				
			}
		}
		else {
			if (temp > 0)
				priorQ.push(temp);
			else if (temp < 0)
				priorQUnder.push(temp);
		}
	}

	return 0;
}