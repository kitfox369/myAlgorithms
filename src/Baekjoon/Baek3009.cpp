#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int x1=0,y1=0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	
	scanf("%d %d", &x1,&y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);

	int x = 0, y = 0;

	if (x1 == x2)
		x = x3;
	else if (x1 == x3)
		x = x2;
	else
		x = x1;
	if (y1 == y2)
		y = y3;
	else if (y1 == y3)
		y = y2;
	else
		y = y1;

	printf("%d %d", x, y);

	return 0;
}