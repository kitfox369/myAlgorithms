#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string a,string b) {
	//string operator로 연산자의 좌변에 있는 문자열 개체가 우변에 있는 문자열 개체보다 작은지 테스트함
	if (a.size()==b.size())	return a<b;		//좌변이 더 작으면 true 반환(sort됨)
	else {
		return a.size() < b.size();
	}
}

int main() {
	
	int N;
	string str;
	vector<string> strArray;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> str;
		strArray.push_back(str);
	}

	sort(strArray.begin(), strArray.end(),compare);		

	str = " ";

	for (int i = 0; i < N; i++) {
		if (str == strArray[i]) continue;		//같은 경우 출력을 하지 않음
		cout << strArray[i] << endl;
		str = strArray[i];
	}

	return 0;
}