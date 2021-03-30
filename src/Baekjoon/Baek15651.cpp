#include<iostream>
using namespace std;

int arr[9] = { 0, };		//1~8의 숫자를 담을 수 있는 배열

void dfs(int cnt, int n, int m)
{
	if (cnt == m)			//탐색을 m개까지 마친 경우
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)		//1~n까지 탐색
	{
        arr[cnt] = i;					//방문하지 않은 자릿수를 arr에 넣음
        dfs(cnt + 1, n, m);
	}
}

int main() {

	int N, M;

	cin >> N >> M;
	dfs(0, N, M);

	return 0;
}