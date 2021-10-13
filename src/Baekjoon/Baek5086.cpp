#include<iostream>
#include<algorithm>
using namespace std;

// 5086번 배수와 약수

int main() {

	int first=-1, second=-1;

	while (1) {
		cin >> first >> second;

		if (first == 0 && second == 0)
			break;

		if (second%first == 0 && second > first)
			cout << "factor\n";
		else if (first > second&&first%second == 0)
			cout << "multiple\n";
		else
			cout << "neither\n";
	}

	return 0;
}