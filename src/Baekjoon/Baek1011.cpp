#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int T=0;
	long x = 0, y = 0;
	vector<int> peopleNum;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%ld %ld", &x, &y);

		long idx = 0,dist=0,count=0;

		dist = (int)sqrt(y - x);		

		if (y - x == dist * dist)	//거리가 제곱수일 때
			count = 2 * dist - 1;
		else if (dist*dist < (y - x) && (y - x) <= dist * dist + dist)	//거리가 제곱수로 딱 떨어지지 않을 때 거리가 큰경우
			count = 2 * dist;
		else if (dist*dist + dist < (y - x) && y - x < (dist + 1)*(dist + 1))//거리가 제곱수로 딱 떨어지지 않을 때 거리가 작은경우
			count = 2 * dist + 1;

		peopleNum.push_back((int)count);
	}
	for (int i = 0; i < peopleNum.size(); i++) {
		printf("%d\n", peopleNum[i]);
	}
	return 0;
}
