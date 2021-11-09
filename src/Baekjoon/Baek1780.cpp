#include<iostream>
using namespace std;

// 1780번 종이의 개수

int** arr;
int zeroNum = 0, oneNum = 0,minusNum=0;

void findSplitBox(int col, int row, int size) {
	int color = arr[col][row];
	bool isCheck = false;
	for (int i = col; i < col + size; i++) {		//정해진 y축의 지점에서 col+size까지 반복
		for (int j = row; j < row + size; j++) {	//정해진 x축의 지점에서 row+size까지 반복
			if (color != arr[i][j])		{

				//첫째줄
				findSplitBox(col, row, size / 3);	
				findSplitBox(col, row + size / 3, size / 3);	
				findSplitBox(col, row + 2*size / 3, size / 3);

				//둘째줄
				findSplitBox(col + size / 3, row, size / 3);	
				findSplitBox(col + size / 3, row+size/3, size / 3);
				findSplitBox(col + size / 3, row+2*size/3, size / 3);

				//셋째줄
				findSplitBox(col + 2* size / 3, row, size / 3);
				findSplitBox(col + 2 * size / 3, row+size/3, size / 3);
				findSplitBox(col + 2 * size / 3, row+2*size/3, size / 3);

				return;
			}
		}
	}

	if (color == 0)	zeroNum++;
	else if(color==1) oneNum++;
	else minusNum++;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, arrayNum;

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

	//삼중 분할(재귀 함수 호출)
	findSplitBox(0, 0, T);

	cout <<minusNum<<"\n"<< zeroNum << "\n" << oneNum;

	return 0;
}