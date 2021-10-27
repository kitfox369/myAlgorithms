#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

// 9012번 괄호

bool Check(string str) {
	stack<char> st;

	for (int i = 0; i < str.length(); i++) {
		char temp = str[i];
		if (temp == '(') {
			st.push(str[i]);			//여는 괄호면 스택을 쌓음
		}
		else {							//닫는 괄호면 스택을 지움
			if (!st.empty())		st.pop();		//만약 쌓인 스택이 있으면 스택을 지움
			else return false;			//쌓인 스택이 없으면 VPS가 아님을 반환
		}
	}

	return st.empty();		//반복문이 끝나고 남아 있으면 false 반환
}

int main() {

	int n;
	string str;
	char* result;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		(Check(str)) ? (cout << "YES\n") :(cout<<"NO\n");
	}

	return 0;
}