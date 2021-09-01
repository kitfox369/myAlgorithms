#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//18870 좌표 압축 문제
//참고 : https://hevton.tistory.com/437
int main() {

	vector<int> v, copy;
	int N, input;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
		copy.push_back(input);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());		//중복된 값을 제외하고 오름차순으로 정렬

	//lower_bound : 이진탐색기반, 
	// 3번째 value의 해당하는 값보다 이상인 원소의 위치를 리턴
	for (int i = 0; i < N; i++) {
		printf("%d ", lower_bound(v.begin(), v.end(), copy[i]) - v.begin());
	}
}