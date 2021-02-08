#include<iostream>
#include<string>
using namespace std;

int main() {
	int N=0,Idx=1,minRoomNum=1;
	scanf("%d", &N);
	
	while (Idx < N) {
		Idx += minRoomNum *6;
		minRoomNum++;
	}
	printf("%d", minRoomNum);
	return 0;
}