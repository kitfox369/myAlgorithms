#include<iostream>
#include<cmath>
using namespace std;

#define PIE 3.14159265358979

int main() {
	int radius=0;

	scanf("%d", &radius);

	//택시 기하학에서 원은 마름모꼴 형태의 정사각형 모습
	printf("%.6f\n", PIE * pow(radius, 2));
	printf("%.6f", 2 * pow(radius, 2));

	return 0;
}