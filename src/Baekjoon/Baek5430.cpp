#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

// 5430번 AC

bool isInverse = false, isError = false;
deque<int> st;

void printError() {
	if (isError)	cout << "error\n";
	else if (st.empty())		cout << "[]\n";
	else if (isInverse) {
		cout << "[";
		while (st.size() > 1) {
			cout << st.back() << ",";
			st.pop_back();
		}
		cout << st.back() << "]\n";
	}
	else {
		cout << "[";
		while (st.size() > 1) {
			cout << st.front() << ",";
			st.pop_front();
		}
		cout<<st.front() << "]\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T,arrayNum;

	cin >> T;

	while(T--){
		string str, arr, temp = "";

		cin >> str;		//함수 받기
		cin >> arrayNum;	//배열 크기 받기
		cin >> arr;		//배열 입력 받기([과, 제거 필요)

		st.clear();

		isInverse = false, isError = false;

		temp = "";
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == '[') continue;
			else if (arr[j] >= '0'&&arr[j] <= '9') {		//10 이상의 숫자(두자리수)도 받기 위해
				temp += arr[j];
			}
			else if ((arr[j]==','||arr[j]==']')&&temp!="") {
				st.push_back(atoi(temp.c_str()));
				temp = "";
			}
		}

		//함수 처리하기
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'R') {			//배열에 있는 숫자의 순서를 뒤집는
				isInverse = !isInverse;		//반대 값으로 변경(0이면 1, 1이면 0)
			}
			else if (str[j] == 'D') {		//첫 번째 숫자를 버리는
				if (st.empty()) {		//만약 배열이 빈 경우 에러 출력
					isError = true;
					break;
				}
				if (isInverse)	st.pop_back();
				else st.pop_front();
			}
		}

		//에러 출력하기
		printError();

	}
	return 0;
}

