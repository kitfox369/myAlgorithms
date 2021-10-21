#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

// 9375번 패션왕 신해빈

int main() {

	int t,n;
	string clothes, kind;
	map<string, int>::iterator iter;
	map<string, int> m;

	cin >> t;

	for (int i = 0; i < t; i++) {
		m.clear();
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> clothes >> kind;
			m[kind]++;			//어떤종류인지 몇개인지 중요(중복되는 종류는 ++해줌)
		}

		int res = 1;
		for (iter = m.begin(); iter != m.end(); iter++) {
			res *= (iter->second + 1);
		}

		cout << res - 1 << "\n";

	}

	return 0;
}