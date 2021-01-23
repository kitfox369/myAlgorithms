#include <iostream>
 
int main() {
    int array[26]={0,};    
    for(int i=0;i<26;i++){
        array[i]=-1;        //모든 배열 -1로 초기화
    }
    char word[100]={"",};
    for(int i=0;i<100;i++){
        scanf("%c",&word[i]);
        if(word[i]=='\0') break;        //입력 값이 없을 때 for문을 빠져나옴
        else if(array[static_cast<int>(word[i])-97]==-1)
            array[static_cast<int>(word[i])-97]=i;
    }
    for(int i=0;i<26;i++){
        printf("%d ",array[i]);
    }
    return 0;
}