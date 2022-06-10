#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//1655번 가운데를 말해요
//최소힙, 최대힙 사용
int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);

    int N,temp;
    priority_queue<int> max;        //최대힙       우선순위 큐는 default로 less<in>를 사용
    priority_queue<int,vector<int>,greater<int>> min;       //최소힙
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;

        (max.size() == min.size()) ? max.push(temp) : min.push(temp);

        if (!max.empty() && !min.empty()&& max.top() > min.top()) {
            //중간 값의 순서가 달라진다면 값 바꾸기
            int maxVal, minVal;
            maxVal = max.top();
            minVal = min.top();
            max.pop();
            min.pop();
            max.push(minVal);
            min.push(maxVal);
        }

        cout << max.top()<<"\n";
    }
    
    return 0;
}