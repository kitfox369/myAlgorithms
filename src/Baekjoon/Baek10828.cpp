#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

// 10828번 스택

stack<string> st;

void getNumSize(string str) {
	string temp;

	if (str == "top") {
		if(st.size()>0)
			cout << st.top() << "\n";
		else
			cout << "-1\n";
	}
	else if (str == "size") {
		cout << st.size() << "\n";
	}
	else if (str == "empty") {
		cout << st.empty() << "\n";
	}
	else if (str == "pop") {
		if (st.size() > 0) {
			cout << st.top()<<"\n";
			st.pop();
		}
		else
			cout << "-1\n";
	}
	else if (str=="push")
	{
		cin >> temp;
		st.push(temp);
	}

}

int main() {

	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		getNumSize(str);
	}

	return 0;
}