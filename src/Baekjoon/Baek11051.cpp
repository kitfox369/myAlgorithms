#include <iostream>
using namespace std;

// 11051번 이항계수 2

//dp
int cache[1001][1001];

//이항 정리 : (N,K) = (N-1,K-1)+(N-1,K)
//나머지(Modulo) 연산 분배 법칙
//각 피연산자에 모듈러 연산을 취한 후, 계산 결과에 대해 다시 한 번 모듈러 연산을 취함5 
int binoCoefficient(int n,int k){
    if(n==k||k==0) return 1;
    //메모이제이션 : 컴퓨터 프로그램이 동일한 계산을 반복해야할 때, 이전에 계산한 값을 메모리에 저로함으로써
    //동일한 계산의 반복 수행을 제거하여 프로그램 실행 속도를 빠르게 하는 기술
    int& ret = cache[n][k]; 
    if(ret!=0) return ret;
    return ret = binoCoefficient(n-1,k-1)%10007+binoCoefficient(n-1,k)%10007;
}

int main() {
    
    int n,k;

    cin>>n>>k;

    cout<<binoCoefficient(n,k)%10007;

    return 0;
}