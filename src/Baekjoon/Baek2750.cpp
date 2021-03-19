#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int  N = 0,num=0;
	vector<int> intArray;

	scanf("%d\n",&N);

	for (int j = 0; j < N; j++) {
		scanf("%d", &num);
		intArray.push_back(num);
	}

	sort(intArray.begin(), intArray.end());

	for (int i = 0; i < intArray.size(); i++) {
		printf("%d\n", intArray[i]);
	}
	
	return 0;
}