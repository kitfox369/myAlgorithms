#include<iostream>

using namespace std;


int main() {
 
    int origin[6] = {1,1,2,2,2,8};
    int temp;
    for (int i = 0; i < 6; i++) {
        cin >> temp;
        cout << origin[i]-temp <<" ";
    }

    return 0;
}