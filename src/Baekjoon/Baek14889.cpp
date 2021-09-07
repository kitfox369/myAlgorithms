#include <iostream>
#include<algorithm>

using namespace std;

//14889번 스타트와 링크
//인용 : https://fjvbn2003.tistory.com/434
int minValue, maxValue;
int arr[20][20];
int N;
bool visited[20];
int diff = 1234567890;

void diffCount(int cnt, int cur) {
	if (cnt == N / 2) {		//2개로 딱 나눠진다면
		int a = 0;
		int b = 0;

		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (visited[i] && visited[j]) {
					a += arr[i][j];
					a += arr[j][i];
				}
				else if (!visited[i] && !visited[j]) {		//그외의 팀 관련 능력치 계산
					b += arr[i][j];
					b += arr[j][i];
				}
			}
		}
		diff = min(diff, abs(a - b));		//능력치 차이의 최솟값
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == false && i > cur) {			//배열이 홀수인 경우 탐색하지 않은 경우
			visited[i] = true;
			diffCount(cnt + 1, i);
			visited[i] = false;
		}
	}
}

int main() {

	cin >> N;
	//배열 입력받기
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	diffCount(0,-1);
	cout << diff;

}