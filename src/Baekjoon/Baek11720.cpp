#include <iostream>

int main() {
	int numberSize,sum=0;
	scanf("%d\n",&numberSize);
	char array[numberSize]={"",};		//int로 받을 시 공백없이 받을 수 없어서 char배열로 진행
	for(int i=0;i<numberSize;i++){	
		scanf("%c",&array[i]);
		//char를 int로 변경하기 위해서는 0의 아스키 코드 값인 48을 빼줘야함
		sum+=static_cast<int>(array[i])-48;	
	}
	printf("%d",sum);
	return 0;
}