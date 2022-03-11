#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

// 1260번 DFS와 BFS

//깊이 우선 탐색
void dfs(vector<int> inputGraph[], bool *visited,int index) {
	visited[index] = true;		//방문했음을 표시
	cout << index<<" ";
	//dfs 탐색 순서
	int grphSize = inputGraph[index].size();
	for (int i = 0; i < grphSize; i++) {
		int connectIdx = inputGraph[index][i];
		if (!visited[connectIdx])
			dfs(inputGraph, visited, connectIdx);
	}
}

//너비 우선 탐색
void bfs(vector<int> inputGraph[],bool *visited,int index) {
	queue<int> que;
	que.push(index);
	visited[index] = true;
	//bfs 탐색 순서
	while (!que.empty()) {
		int visitIdx = que.front();
		que.pop();
		cout << visitIdx<<" ";
		int grphSize = inputGraph[visitIdx].size();
		for (int i = 0; i < grphSize; i++) {
			//방문한 Idx와 연결된 원소들을 que에 넣기
			int connectIdx = inputGraph[visitIdx][i];
			if (!visited[connectIdx]) {		//만약 연결된 원소를 방문하지 않았다면
				que.push(connectIdx);		//방문할 노드로 선정
				visited[connectIdx] = true;
			}
		}
	}
	
	
}

int main() {

	int N, M, V;		//정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호

	cin >> N >> M >> V;

	int size = N + 1;
	//N개만큼의 배열 만들기
	bool* visited = new bool[size] {false, };			//방문 유무를 저장하는 배열
	vector<int>* graph = new vector<int>[size];
	graph->push_back(1);

	for (int i = 0; i < M; i++) {
		int origin, connect;
		cin >> origin >> connect;
		graph[origin].push_back(connect);
		graph[connect].push_back(origin);
	}

	//정렬
	for (int i = 0; i < size; i++) {
		sort(graph[i].begin(),graph[i].end());
	}

	dfs(graph,visited, V);
	cout << endl;
	visited = new bool[size]{ false, };		//방문유무를 다시 초기화해줌(재사용 위해)
	bfs(graph, visited,V);

	delete [] visited;		//메모리 해제 
	//vector 메모리 해제
	graph->clear();
	vector<int>().swap(*graph);

	return 0;
}