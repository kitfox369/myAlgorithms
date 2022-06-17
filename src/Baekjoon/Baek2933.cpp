#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define y first
#define x second
using namespace std;

//2933번 미네랄

//2차원 배열 선언
char arr[101][101];
int visited[101][101];      //dfs를 위한 방문 배열
int R, C;
vector<pair<int,int>> cluster;
int arrow[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void DFS(int yIdx, int xIdx) {
    if (arr[yIdx][xIdx] == '.' || visited[yIdx][xIdx]) return;
    visited[yIdx][xIdx] = true;
    cluster.push_back({yIdx,xIdx});
    //좌우위아래 탐색
    for (int i = 0; i < 4; i++) {
        int ny = yIdx + arrow[i][0];
        int nx = xIdx + arrow[i][1];    
        if (nx >= 0 && nx < C && ny >= 0 && ny < R)
            DFS(ny, nx);
    }
}

void checkCluster() {
    memset(visited, 0, sizeof(visited));
    for (int a = 0; a < R; a++) {
        for (int b = 0; b < C; b++) {
            if (arr[a][b] == '.' || visited[a][b]) continue;
            cluster.clear();
            DFS(a,b);
            vector<int> low(C, -1);     //vector(컨테이너 크기, 각각 할당될 값)
            for (int z = 0; z < cluster.size(); z++) {
                pair<int, int> p= cluster[z];
                low[p.x] = max(low[p.x], p.y);
                arr[p.y][p.x] = '.';
            }

            //얼마나 밑으로 옮길지 i에 넣기
            int lowmove = R;
            for (int i, j = 0; j < C; j++) {
                if (low[j] == -1) continue;
                i = low[j];

                //'.'이 아닌경우, 탐색 높이가 높이보다 작은 경우
                while (i < R && arr[i][j] == '.') {
                    i++;
                }
                lowmove = min(lowmove, i - low[j] - 1);
            }

            for (int i = 0; i < cluster.size(); i++) {
                pair<int, int> p = cluster[i];
                p.y += lowmove;
                arr[p.y][p.x] = 'x';
                visited[p.y][p.x] = true;
            }
        }
    }
    
}

void shoot(int orderNum,int height) {
    //왼쪽인지 오른쪽인지 판단
    height = R - height;
    if (orderNum % 2 == 0) {
        for (int i = 0; i < C; i++) {
            if (arr[height][i] == 'x') {
                arr[height][i] = '.';
                break;
            }
        }
    }
    else {
        for (int i = C-1; i >= 0; i--) {
            if (arr[height][i] == 'x') {
                arr[height][i] = '.';
                break;
            }
        }
    }
    
    checkCluster();
}

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    int N,height=0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> height;
        shoot(i, height);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}