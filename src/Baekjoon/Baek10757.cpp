#include<iostream>
#include<string>
using namespace std;

int main() {
	string A, B, C = "";
	cin >> A >> B;		//string으로 입력 받음
	
	//길이가 작은 만큼만 돌림
	int length = 0;
	A.length() > B.length() ? length = B.length() : length = A.length();
	int value=0, rest=0;
	for (int i = 0; i < length; i++) {
		int sum = A[A.length() - i-1]-'0' + B[B.length() - i-1] - '0'+ value;
		rest = sum % 10;
		C += rest+'0';
		value = 0;
		if (sum >= 10)
		{
			value = 1;

		}
	}
    //나머지 길이 만큼 계산
	if (A.length() > length) {
		for (int i = length; i < A.length(); i++) {
			C += (A[A.length() - i - 1] + value-'0') %10+'0';
			if (A[A.length() - i - 1] + value - '0' >= 10)
				value = 1;
			else
				value = 0;	
		}
	}
	else if(B.length()>length){
		for (int i = length; i < B.length(); i++) {
			C += (B[B.length() - i - 1] + value - '0') % 10+'0';
			if (B[B.length() - i - 1] + value - '0' >= 10) {
				value = 1;
			}
			else
				value = 0;
		}
	}
	else {      //길이가 동일한 경우
		if (value == 1) {       //받아 올릴 1이 있는경우
			C += '1';
			value = 0;
		}
	}
    //큰 길이 만큼 모두 계산 후 받아 올릴 1이 있는경우
	if (value == 1)
		C += value+'0';

    //거꾸로 받았기 때문에 거꾸로 출력해줌
	for (int i = C.length()-1; i >= 0; i--) {
		cout << C[i];
	}

	return 0;
}