#include<iostream>
using namespace std;

// 2630번 색종이 만들기

int** arr;
int whiteNum = 0, blueNum = 0;

void findSplitBox(int col,int row,int size) {
	int color = arr[col][row];
	bool isCheck = false;
	for (int i = col; i < col + size; i++) {		//정해진 y축의 지점에서 col+size까지 반복
		for (int j = row; j < row + size; j++) {	//정해진 x축의 지점에서 row+size까지 반복
			if (color == 0 && arr[i][j] == 1)		isCheck = true;		//두개의 색상이 맞지 않는 경우
			else if (color == 1 && arr[i][j] == 0)		isCheck = true;	//두개의 색상이 맞지 않는 경우

			if (isCheck) {
				findSplitBox(col, row, size / 2);		//제2사분면
				findSplitBox(col, row+size/2, size / 2);		//제1사분면
				findSplitBox(col+size/2, row, size / 2);		//제3사분면
				findSplitBox(col+size/2, row+size/2, size / 2);	//제4사분면
				return;
			}
		}
	}

	if (color == 0)	whiteNum++;
	else blueNum++;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T,arrayNum;

	cin >> T;

	//2차원 배열  동적 선언
	arr = (int**)malloc(sizeof(int*)*T);
	for (int i = 0; i < T; i++) {
		arr[i] = (int*)malloc(sizeof(int)*T);
	}

	//입력받기
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++) {
			cin >> arr[i][j];
		}
	}

	//이분 분할(재귀 함수 호출)
	findSplitBox(0,0, T);

	cout << whiteNum << "\n" << blueNum;

	return 0;
}

