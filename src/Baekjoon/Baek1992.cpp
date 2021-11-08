#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;

// 1992번 쿼드트리

vector<string> arr;

void findSplitBox(int col, int row, int size) {
	char color = arr[col][row];
	bool isCheck = false;
	for (int i = col; i < col + size; i++) {		//정해진 y축의 지점에서 col+size까지 반복
		for (int j = row; j < row + size; j++) {	//정해진 x축의 지점에서 row+size까지 반복
			if(arr[i][j]!=color){			//만약 비교하는 컬러와 다른 색상이 나온다면 다시 분할
				cout << "(";
				findSplitBox(col, row, size / 2);		//제2사분면
				findSplitBox(col, row + size / 2, size / 2);		//제1사분면
				findSplitBox(col + size / 2, row, size / 2);		//제3사분면
				findSplitBox(col + size / 2, row + size / 2, size / 2);	//제4사분면
				cout << ")";
				return;
			}
			
		}
	}

	//분할이 되지 않고 무사히 나온 경우 color 출력
	cout << color;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	//배열 받기(string으로 한줄씩 받아야함)
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}

	//쿼드 트리 계산
	findSplitBox(0, 0, N);

	return 0;
}