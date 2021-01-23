#include <iostream>
using namespace std;

int main() {
   char word[1000001]={" ",};
   char mostAlpha[26]={" ",};   //알파벳 갯수가 26개이므로
   int repetNum[26]={0,};      //대문자 소문자 합하면 52
   int idx=0,alphaCount=0;
   bool isIncrease=false;
   scanf("%s",word);
   while(word[idx]!='\0'){
   		int idxSame=0;
   		if(word[idx]>=97) word[idx]-=32;		//소문자일 경우 아스키코드 32를 빼주어 대문자로 변환
    	if(alphaCount>=1){
	         for(int i=0;i<alphaCount;i++){
	            //같은 것 있는지 체크 및 같은 자리의 배열 번호 저장
	            if(word[idx]==mostAlpha[i]){
	              isIncrease=false;
	              idxSame=i;
	              break;
	            }
	            else{
	               isIncrease=true;
	            }
	         }
	         if(isIncrease){		//for문이 끝나고 alphaCount를 더해주어야하기 때문
	        	mostAlpha[alphaCount]=word[idx];
	            repetNum[alphaCount]=1;
	         	alphaCount++;		//그렇지 않으면 더 많은 for문을 발생시킴
	         }
	         else
	         {
	         	 repetNum[idxSame]++;	//아니면은 같은것에 ++해줌
	         }
    	}
    	else
    	{
	         mostAlpha[0]=word[idx];
	         repetNum[0]=1;
	         alphaCount++;
	    }
    	idx++;
   }
   //제일 숫자가 큰 것을 뽑음
   int mostNum=0,mostNumIdx=0;
   bool isDupli=false;
   for(int i=0;i<alphaCount;i++){
      if(mostNum<repetNum[i]){ 
         mostNum=repetNum[i];
         isDupli=false;			//최댓값이 바뀔경우 false
         mostNumIdx=i;
      }
      else if(mostNum==repetNum[i]&&repetNum[i]>1){
         isDupli=true;			//같은 최대값이 있다면 true, 하지만 1초과여야함
      }
   }
   
   if(isDupli){
      printf("?");
   }
   else{
      	printf("%c",mostAlpha[mostNumIdx]);
   }
   return 0;
}