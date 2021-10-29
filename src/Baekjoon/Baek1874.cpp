#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// 1874번 스택 수열

int main() {

	int n,iTemp;
	int count = 1;
	stack<int> st;
	vector<int> temp;			

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> iTemp;

		while (count <= iTemp) {
			st.push(count);
			count += 1;
			temp.push_back(0);
		}

		if (st.top() == iTemp) {
			st.pop();
			temp.push_back(1);
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	
	for (int i = 0; i < temp.size(); i++)
		(temp[i] == 0) ? cout << "+\n" : cout << "-\n";

	return 0;
}