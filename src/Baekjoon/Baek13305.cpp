#include<iostream>
#include<algorithm>
using namespace std;

// 13305번 주유소
// 그리디 알고리즘 : 매 선택에서 지금 이 순간 당장 최적인 답을 선택하여 적합한 결과를 도출

long long N, sum = 0;		//도시의 갯수, 최소 비용
long long dist[100001];
long long price[100001];
long long greedy;

int main() {

	cin >> N;

	//거리 입력
	for (int i = 1; i <= N-1; i++)
		cin >> dist[i];
	//리터당 기름 가격 입력
	for (int i = 1; i <= N; i++)
		cin >> price[i];

	greedy = 1000000000;		//최대 비용으로 셋팅

	for (int i = 1; i <= N - 1; i++) {
		if (price[i] < greedy)		//이전에 사용한 비용이 현재 비용보다 클 때 갱신
			greedy = price[i];
		sum += greedy * dist[i];
	}

	cout << sum;

	return 0;
}