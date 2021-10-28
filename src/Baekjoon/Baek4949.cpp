#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

// 4949번 균형잡힌 세상

bool Check(string str) {
	stack<char> st;

	for (int i = 0; i < str.length(); i++) {
		char temp = str[i];
		if (temp == '('|| temp == '[') {
			st.push(temp);			//여는 괄호면 스택을 쌓음
		}
		else if(temp==')'){							//닫는 괄호면 스택을 지움
			if (!st.empty()&&st.top()=='(')		st.pop();		//만약 쌓인 스택이 있으면 스택을 지움
			else return false;
		}
		else if (temp == ']') {
			if (!st.empty() && st.top() == '[')		st.pop();
			else return false;
		}
	}

	return st.empty();		//반복문이 끝나고 남아 있으면 false 반환
}

int main() {

	string str;

	while(1){
		getline(cin, str);
		if (str.length()==1&&str[0] == '.') break;
		(Check(str)) ? (cout << "yes\n") :(cout<<"no\n");
	}

	return 0;
}