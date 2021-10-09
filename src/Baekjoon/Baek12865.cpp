#include<iostream>
#include<algorithm>

using namespace std;

// 12865번 평범한 배낭

int N,K;
int dp[103][100003];
int W[103]; //무게
int V[103]; //가치

int main(){

    cin>>N;
    cin>>K;

    //입력받기
    for(int i=1;i<=N;i++){
        cin>>W[i]>>V[i];
    }

    //계산
    for(int i=1;i<=N;i++){      //물건의 갯수만큼
        for(int j=1;j<=K;j++){  //준서가 가지고 갈 수 있는 무게
            if(j-W[i]>=0)       //해당 물건의 가치가 준서가 가지고 갈 수 있는 무게보다 작을 때
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+V[i]);     //i번째 물건을 담지 않은 경우, i번째 물건을 담은 경우
            else                //해당 물건의 가치가 준서가 가지고 갈 수 있는 무게보다 클 때
                dp[i][j] = dp[i-1][j];  //i번째 물건을 담지 않은 경우
        }
    }

    cout<<dp[N][K];

    return 0;
}