#include<iostream>

using namespace std;

bool equals(int rValue,int lValue, int* outValue) {
    if (rValue == lValue) {
        *outValue = rValue;
        return true;
    }
    else
        return false;
}

int main() {
    
    int firstDice, secondDice, thirdDice;
    int value=0;
    cin >> firstDice >> secondDice >> thirdDice;
    
    if (firstDice == secondDice&& secondDice == thirdDice) {     //만약 세개가 같은 값이면
        cout << 10000 + firstDice * 1000;
    }
    else if (equals(firstDice,secondDice,&value)
        || equals(secondDice, thirdDice, &value)
        || equals(firstDice, thirdDice, &value)) {     //만약 두개가 같은 값이면
        cout<<1000+ value *100;
    }
    else {
        //그 중 가장 큰눈
        value = max(max(firstDice, secondDice), thirdDice);
        cout << value * 100;
    }

    return 0;
}