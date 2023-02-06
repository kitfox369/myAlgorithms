#include<iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int* array = new int[N];

	for (int i = 0;i < N;i++) {
		int temp = 0;
		cin >> temp;
		array[i] = temp;
	}

	int v;
	cin >> v;
	int count = 0;
	for (int i = 0;i < N;i++) {
		if (array[i] == v) count++;
	}

	cout << count;

	return 0;
}