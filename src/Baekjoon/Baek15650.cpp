#include<iostream>
using namespace std;

int arr[9] = { 0, };		//1~8의 숫자를 담을 수 있는 배열
bool visited[9] = { 0, };	//이미 탐색을 마쳤는지 유무	0:false 1:true

void dfs(int cnt,int idx, int n, int m)
{
	if (cnt == m)			//탐색을 m개까지 마친 경우
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++)		//idx~n까지 탐색, 이미 찾은 조합은 다시 뽑지 X
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;					//방문하지 않은 자릿수를 arr에 넣음
			dfs(cnt + 1, i+1, n, m);
			visited[i] = false;
		}
	}
}

int main() {

	int N, M;

	cin >> N >> M;
	dfs(0,1, N, M);

	return 0;
}