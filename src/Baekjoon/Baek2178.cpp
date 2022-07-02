#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 101

using namespace std;

//2178 미로 탐색

int MAP[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];
int arrow[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;
pair<int, int> startP, endP;

queue < pair<int, int>> Q;

void BFS() {
    
    Q.push(make_pair(startP.first, startP.second));

    dist[startP.first][startP.second]++;
    visited[startP.first][startP.second] = 1;

    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        //좌우위아래 탐색
        for (int i = 0; i < 4; i++) {
            int ny = y + arrow[i][0];
            int nx = x + arrow[i][1];


            if ((nx >= 0 &&nx < M) && (ny >= 0 && ny < N)
                && MAP[ny][nx] == 1 &&!visited[ny][nx]) {
                visited[ny][nx] = 1;
                Q.push(make_pair(ny, nx));
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
    cout << dist[endP.first-1][endP.second-1];
}


void input() {
    string num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        for (int j = 0; j < M; j++) {
            MAP[i][j] = num[j]-'0';
        }
    }
}

int main() {

    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int tmp;
    cin >> N>>M;
    startP = make_pair(0, 0);
    endP = make_pair(N, M);
    
    input();
    BFS();

    return 0;
}