#include<iostream>
using namespace std;

// 3046번 R2

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//R1과 S가 주어짐
	int R1, S;

	cin >> R1 >> S;

	//R2=2S-R1
	cout << 2 * S - R1;

	return 0;
}