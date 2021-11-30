#include <iostream>
#include<vector>
using namespace std;

//6603번 로또

int arr[13];
int lotto[6];
int N;

void printCase(int arrIdx, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << endl;
		return;
	}
	//경우의 수 체크
	for (int i = arrIdx; i < N; i++) {
		lotto[depth] = arr[i];
		printCase(i + 1, depth + 1);
	}
}

int main() {

	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		printCase(0, 0);
		cout << endl;
	}

	return 0;
}