#include <iostream>
using namespace std;

int getHansuCount(int num){
	int count=0;
	if(num<100)
	{
        count = num;
	}
	else{
	  count+=99;
	  for(int i=100;i<=num;i++){
	     bool isHanSu=true;
	     int idx=i,diff=(idx%10);      //,나머지
	     idx/=10;
	     int rest=(idx%10);      //2번째 자릿수 삽입
	     diff = diff-rest;   //1번째와 2번째 자릿수의 차이 삽입
	     idx/=10;
	     
	     while(idx>0){
	        if(diff!=rest-(idx%10)){
	           isHanSu=false;
	           break;
	        }
	        rest=idx%10;
	        idx/=10;
	     }
	     if(isHanSu)
	     {
	        count++;
	     }
	  }
	}
	return count;
}


int main() {
   int num,count=0;
   scanf("%d",&num);
   count = getHansuCount(num);
   printf("%d",count);
   return 0;
}