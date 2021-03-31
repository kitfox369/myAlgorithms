//https://cryptosalamander.tistory.com/58 참고
#include <iostream>
using namespace std;

int col[15];

bool check(int level)
{
	for (int i = 0; i < level; i++){
        // 같은 라인인 경우 / 대각선인 경우
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i){
			return false;
        }
    }
    //검사 결과 해당 자리가 맞을 때
	return true;
}

void nqueen(int x,int N,int& total)
{
	if (x == N)
		total++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[x] = i;
			if (check(x))
				nqueen(x + 1,N,total);      //check 해서 true면 다음행의 퀸 배치
		}
	}
}
int main() {
	int N, total = 0;
	
	cin >> N;
	nqueen(0,N,total);
	cout << total;
}