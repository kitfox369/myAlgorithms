#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int x=0,y=0,w=0,h=0;
	
	scanf("%d %d %d %d", &x,&y,&w,&h);

	int yDist = 0, xDist = 0, minDist=0,xyMin=0;

	yDist = abs(h - y);		//y에서 h까지의 직선 거리
	xDist = abs(w - x);		//x에서 w까지의 직선 거리
	//yDist와 xDist 중 짧은 거리
	minDist = yDist > xDist ? xDist : yDist;
	//x와 y가 원점까지의 직선거리 중 짧은 거리 
	xyMin = y > x ? x : y;
	if (xyMin > minDist) {
		printf("%d", minDist);
	}
	else {
		printf("%d", xyMin);
	}
	

	return 0;
}