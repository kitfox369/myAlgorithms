#include <iostream>
using namespace std;

//1476번 날짜 계산

int main() {

	//지구15 태양28 달19
	int E, S, M;
	int year = 1;
	cin >> E >> S >> M;

	while (1) {
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) break;
		else year++;
	}

	cout << year;

	return 0;
}