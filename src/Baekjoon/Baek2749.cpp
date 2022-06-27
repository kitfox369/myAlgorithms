#include<iostream>
#include<cmath>

using namespace std;

//2749번 피보나치 수 3
//피사노 주기를 이용

long long arr[1500050];     //메모이제이션
int m = 1000000;            //나누는 수
int cycle;

int cycle_func() {
    int k=0,tmp=m;
    while (tmp > 1) {
        tmp /= 10;
        k++;
    }

    return 15 * pow(10, k - 1);
}

void pisano_fibo() {
    arr[0] = 0;
    arr[1] = 1;
    //파사노 주기에 의하여 1500000의 값들이 반복된 후에 다시 재 반복됨
    cycle = cycle_func();
    for (int i = 0; i < cycle; i++) {
        arr[i + 2] = (arr[i+1]+arr[i])%m;
    }
}

int main() {

    cin.tie(NULL);cout.tie(NULL);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;
    pisano_fibo();
    cout << arr[n % cycle];

    return 0;
}