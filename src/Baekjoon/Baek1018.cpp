//https://cocoon1787.tistory.com/154 블로그 참고
#include<iostream>
#include<algorithm>
using namespace std;

int chess[51][51];

int checkChess(int x, int y)
{
	int cnt1 = 0,cnt2 = 0;

	for (int i = x; i < x + 8; i++) {	//8x8 칸으로 움직임
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == chess[i][j]) cnt1++; //WB 일때
			if ((i + j + 1) % 2 == chess[i][j]) cnt2++; //BW 일때
		}
	}

	return min(cnt1, cnt2); // 둘 중 최소값 반환
}

int main()
{
	int N, M;
	int minValue = 2500; // 최대로 가질 수 있는 최소 값 50x50
	char c;

	scanf("%d %d\n", &N, &M);

	for (int i = 0; i < N; i++) { // B는 '0', W는 '1'로 저장
		for (int j = 0; j < M; j++) {
			scanf("%c",&c);
			if (c == 'B') chess[i][j] = 0;
			else chess[i][j] = 1;
		}
        if(i<N-1)
			scanf("\n");
	}

	for (int i = 0; i <= N - 8; i++) { // checkChess() 함수에 8x8 사각현 첫번째 값 위치 전달
		for (int j = 0; j <= M - 8; j++) {
			if (minValue > checkChess(i, j))		//결과값이 minValue보다 작을 때 갱신해줌
				minValue = checkChess(i, j);
		}
	}

	printf("%d", minValue);
}