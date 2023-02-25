#include<iostream>

using namespace std;

int main() {

	unsigned long int sum = 0;
	unsigned long int temp = 0;

	for (int i = 0;i < 3;i++) {
		cin >> temp;
		sum += temp;
	}

	cout << sum;

	return 0;
}