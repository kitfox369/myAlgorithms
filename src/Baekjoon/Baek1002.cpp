#include<iostream>
#include<cmath>
using namespace std;

void swap(int& r1, int& r2) {
	int temp;
	temp = r1;
	r1 = r2;
	r2 = temp;
}

int main() {
	int T=0,x1=0,y1=0,r1=0,x2=0,y2=0,r2=0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        //r1이 더 큰 경우 스왑 함수를 통해 r1과 r2를 변경
		if (r1 > r2) swap(r1, r2);

		float distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2));

		if (distance < r1 + r2&&distance>r2-r1) {
			printf("2\n");
		}
		else if (distance == r1 + r2||(distance==r2-r1&&distance!=0)) {
			printf("1\n");
		}
		else if (distance > r1 + r2||distance<r2-r1) {
			printf("0\n");
		}
		else if(distance==0){
			if(r1==r2)
				printf("-1\n");
			else
				printf("0\n");
		}

	}

	return 0;
}