#include<iostream>

using namespace std;

// 2920번 음계

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool isStep = true;
	int temp;
	int perior = 0;
	cin >> temp;
	if (temp == 1) isStep = true;
	else isStep = false;
	perior = temp;
	int i;
	for (i = 1; i < 8; i++) {
		cin >> temp;
		if (isStep&&temp - perior != 1) {
			cout << "mixed";
			break;
		}
		else if (!isStep&&perior - temp != 1) {
			cout << "mixed";
			break;
		}
		perior = temp;
	}

	if (i == 8) {
		if (isStep) cout << "ascending";
		else cout << "descending";
	}
	
	return 0;
}