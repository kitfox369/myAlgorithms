#include <iostream>

int main() {
	int arrayNum,repetition;
	scanf("%d",&arrayNum);
	char array[20]={" ",};	//공백으로 초기화
    char *arrayPtr = array;
	char repetArray[160]={" ",};	//최대 8번 가능하기 때문에 20X8
	for(int i=0;i<arrayNum;i++){
		int idx=0,count=0;
		scanf("%d %s",&repetition,arrayPtr);
		while(array[idx]!='\0'){
			for(int j=count;j<count+repetition;j++){
				repetArray[j]=array[idx];
				printf("%c",repetArray[j]);
			}
			count+= idx*repetition;
			idx++;
		}
		printf("\n");
	}
	return 0;
}