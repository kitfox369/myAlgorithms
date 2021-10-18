#include <iostream>
using namespace std;

// 11050번 이항계수

int factorial(int num){
    if(num==0) return 1;

    int result = 1;

    for(int i=num;i>=1;i--){
        result*=i;
    }

    return result;
}

int main() {
    
    int n,k;

    cin>>n>>k;

    cout<<factorial(n)/(factorial(k)*factorial(n-k));

    return 0;
}