#include <iostream>
#include <algorithm>

using namespace std;

//14888번 연산자 끼워넣기
int minValue= 1000000001, maxValue= -1000000001;
int operatorNum[4];
int numArray[12];
int N;

void minMaxFun(int plus, int minus, int multiply, int divide, int idx,int result) {
	if (idx == N) {
		maxValue = max(maxValue,result);
		minValue = min(minValue,result);
	}
	
	if (plus > 0)
		minMaxFun(plus - 1, minus, multiply, divide, idx + 1, result + numArray[idx]);
	if (minus > 0)
		minMaxFun(plus, minus - 1, multiply, divide, idx + 1, result - numArray[idx]);
	if (multiply > 0)
		minMaxFun(plus, minus, multiply - 1, divide, idx + 1, result * numArray[idx]);
	if (divide > 0)
		minMaxFun(plus, minus, multiply, divide - 1, idx + 1, result / numArray[idx]);

}

int main() {
	
	//입력 받기
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numArray[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operatorNum[i];
	}
	minMaxFun(operatorNum[0], operatorNum[1], operatorNum[2], operatorNum[3], 1,numArray[0]);
	cout << maxValue << '\n' << minValue;

}