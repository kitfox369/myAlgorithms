#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>

using namespace std;

//6087번 레이저 통신

char MAP[101][101];
int visited[101][101];
int w, h;
int arrow[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

pair<int, int> startP, endP;
queue<pair<int,int>> cntDir;
queue < pair<int, int>> Q;
void BFS() {
    for (int i = 0; i < 4; i++) {
        Q.push(make_pair(startP.first, startP.second));
        cntDir.push(make_pair(0, i));
    }
    visited[startP.first][startP.second] = 0;

    while (Q.empty() == 0) {
        int y = Q.front().first;
        int x = Q.front().second;
        int cnt = cntDir.front().first;
        int dir = cntDir.front().second;
        Q.pop();
        cntDir.pop();
        //좌우위아래 탐색
        for (int i = 0; i < 4; i++) {
            int ny = y + arrow[i][0];
            int nx = x + arrow[i][1];
            int nCnt = cnt;

            if (nx <0 || nx >= w || ny < 0 || ny >=h) continue;
            if (MAP[ny][nx] == '*') continue;
            if (dir != i) nCnt++;
            if (visited[ny][nx] >= nCnt) {
                visited[ny][nx] = nCnt;
                Q.push(make_pair(ny, nx));
                cntDir.push(make_pair(nCnt, i));
            }
        }
    }
    cout << visited[endP.first][endP.second];
}

void input() {
    bool isFirst = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'C') {
                (isFirst) ? startP = make_pair(i, j) : endP = make_pair(i, j);
                isFirst = false;
            }
            visited[i][j] = 10001;
        }
    }
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> w >> h;
    
    input();
    BFS();


    return 0;
}