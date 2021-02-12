#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int num=0,H=0,V=0,N=0;
	vector<int> roomNum;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d", &H,&V,&N);
		int floor;
		if (N%H == 0)floor = H;
		else floor = N % H;
		roomNum.push_back((floor *100)+((N-1)/H+1));
	}
	for (int i = 0; i < roomNum.size(); i++) {
		printf("%d\n", roomNum[i]);
	}
	return 0;
}