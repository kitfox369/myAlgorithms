#include<iostream>
//#include<Windows.h>
#include<deque>
#include<vector>

using namespace std;

int main() {
    
    int N, K,L;     //N : 보드의 크기, K : 다음 줄에 사과의 개수, L : 뱀의 방향 변환 횟수
    int column, row;
    int currentX=0, currentY=0;
    int arrIdx = 0, turnIdx=0;          //arrIdx : 방향배열 인덱스, turnIdx : 방향 회전배열 인덱스
    int arrow[4][2] = { {1,0},              //오른쪽
                                {0,1},              //아래
                                {-1,0},             //왼쪽
                                {0,-1} };           //위
    deque<vector<int>> body;

    cin >> N;

    //해당 배열만큼 2차원 행렬 만들기
    int** board = new int* [N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    board[0][0] = 1;
    vector<int> point;
    point.push_back(0);
    point.push_back(0);
    body.push_back(point);

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> row >> column;
        board[row-1][column-1] = 2;
    }
    cin >> L;
    int* turn = new int[L];
    int* direction = new int[L];
    int lValue;
    char rValue;

    for (int i = 0; i < L; i++) {
        cin >> lValue >> rValue;
        turn[i] = lValue;
        direction[i] = rValue;
    }

    int time = 0;

    while (time < 10000) {

        /* {
            Sleep(1000);
            system("cls");

            cout << "Time :" << time+1 << endl;
            //출력해서 확인하기
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << board[i][j] << " ";
                }
                printf("\n");
            }
        }*/

        if (time == turn[turnIdx] && time != 0) {
            if (direction[turnIdx] == 'D') {
                arrIdx++;
            }
            if (direction[turnIdx] == 'L') {
                arrIdx--;
            }
            turnIdx++;
        }


        if (arrIdx > 3)
            arrIdx = arrIdx % 4;
        if (arrIdx < 0) {
            arrIdx = 4 + arrIdx;
        }

        //오른쪽으로 이동하는 것
        currentX += arrow[arrIdx][0];
        currentY += arrow[arrIdx][1];
       
        if ((currentX < 0 || currentX >= N) ||(currentY < 0 || currentY >= N))
            break;
        if (board[currentY][currentX] == 1)
            break;

        if (board[currentY][currentX] == 2) {
            //만약 사과가 있다면
            point.clear();
            point.push_back(currentY);
            point.push_back(currentX);
            body.push_front(point);

            for (size_t i = 0; i < body.size(); i++) {
                board[body[i][0]][body[i][1]] = 1;
            }
        }
        else {
            //맨끝의 값의 자리를 0으로 바꿔주기
            board[body.back()[0]][body.back()[1]] = 0;
            //처음의 값을 뒤로 밀어주기

            for (size_t  i = body.size() - 1; i >0 ; i--) {
                int temp = body[i-1][0];
                body[i][0] = temp;
                temp = body[i-1][1];
                body[i][1] = temp;
            }

            //첫번째 머리움직이기
            body[0][0]= currentY;
            body[0][1]= currentX;

            for (size_t i = 0; i < body.size(); i++) {
                board[body[i][0]][body[i][1]] = 1;
            }
        }

        time++;
    }

    cout << time + 1;

    //할당 해제
    for (int i = 0; i < N; i++)
        delete[] board[i];

    return 0;
}