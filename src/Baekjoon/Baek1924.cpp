#include<iostream>
using namespace std;

// 1924번 2007년

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int X, Y;
	int num = 0;
	//년 월 받아오기
	cin >> X >> Y;

	for (int i = 1; i < X; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			num += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			num += 30;
		else
			num += 28;
	}

	num += Y;
	num %= 7;

	if (num == 0)cout << "SUN";
	else if (num == 1) cout << "MON";
	else if(num==2)cout << "TUE";
	else if (num == 3)cout << "WED";
	else if (num == 4)cout << "THU";
	else if (num == 5)cout << "FRI";
	else if (num == 6)cout << "SAT";
	

	return 0;
}