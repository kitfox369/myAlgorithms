#include <iostream>
using namespace std;

// 1010번 다리 놓기

int main() {
    
    int t,n,m;

    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n>>m;
        long long ans = 1;
        int r=1;
        for(int j=m;j>m-n;j--){
            ans *= j;
            ans /= r++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}