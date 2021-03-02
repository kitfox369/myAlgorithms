#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int side1 = 0, side2 =0,side3 =0;

	while (1) {
		scanf("%d %d %d", &side1,&side2,&side3);
		if (side1 == 0||side2==0||side3==0) break;
		
		int longSide = 0, shortSide = 0, shortSide2 = 0;
		if (side1 >= side2 && side1 >= side3) {
			longSide = side1;
			shortSide = side2;
			shortSide2 = side3;
		}
		else if (side2 >= side1 && side2 >= side3) {
			longSide = side2;
			shortSide = side1;
			shortSide2 = side3;
		}
		else {
			longSide = side3;
			shortSide = side1;
			shortSide2 = side2;
		}
		
		if(pow(longSide,2)==pow(shortSide,2)+ pow(shortSide2, 2))
			printf("right\n");
		else
			printf("wrong\n");

	}
    
	return 0;
}