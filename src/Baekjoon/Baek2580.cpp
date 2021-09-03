#include <iostream>
#include <vector>

using namespace std;

//2580 스도쿠 문제
//코드 인용 : https://cryptosalamander.tistory.com/59

int sudokuBoard[9][9];
vector<pair<int, int>> points;		//빈칸들의 위치 집합
int countBlank = 0;		//빈칸의 갯수
bool completeAllNum = false;	//모든 빈칸을 채웠는지

//중복되는 숫자가 없는지 판단
bool checkRepeated(pair<int, int> p) {
	int square_x = p.first / 3;
	int square_y = p.second / 3;
	for (int i = 0; i < 9; i++) {
		if (sudokuBoard[p.first][i] == sudokuBoard[p.first][p.second] && i != p.second)
			return false; // 같은 행에 같은 숫자가 있으면 false
		if (sudokuBoard[i][p.second] == sudokuBoard[p.first][p.second] && i != p.first)
			return false; // 같은 열에 같은 숫자가 있으면 false
	}
	for (int i = 3 * square_x; i < 3 * square_x + 3; i++) {
		for (int j = 3 * square_y; j < 3 * square_y + 3; j++)
		{
			if (sudokuBoard[i][j] == sudokuBoard[p.first][p.second])
			{
				if (i != p.first && j != p.second)
					return false; // 3x3 안에 같은 숫자가 있으면 false 반환
			}
		}
	}
	return true; // 앞의 조건 만족시 중복되는 숫자 없다고 판단
}

void sudoku(int N) {
	if (N == countBlank) // 빈칸의 개수=카운트한 N의 갯수
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << sudokuBoard[i][j] << ' ';
			cout << '\n';
		} // 결과 출력
		completeAllNum = true; // 플래그 true로 변경
		return;
	}
	for (int j = 1; j <= 9; j++)
	{
		sudokuBoard[points[N].first][points[N].second] = j; // 1~9 까지의 숫자를 넣고 적합한지 체크
		if (checkRepeated(points[N])) // 적합하다면 다음 빈칸을 채우는 함수 호출
			sudoku(N + 1);
		if (completeAllNum) // 스도쿠가 완성됬을경우 함수 종료
			return;
	}
	sudokuBoard[points[N].first][points[N].second] = 0;// 최적해를 못찾았을 경우 값 초기화
	return;
}

int main() {
	pair<int, int> point;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> sudokuBoard[i][j];
			if (sudokuBoard[i][j] == 0)
			{
				countBlank++;	//빈칸 갯수 세기
				point.first = i;
				point.second = j;
				points.push_back(point); // 빈칸의 좌표 저장
			}
		}
	sudoku(0);		//0번부터 체크 시작
}