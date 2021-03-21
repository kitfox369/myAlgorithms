#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int frequency[8001] = { 0, };		//- 값을 생각해서 x2배만큼 할당

int main() {

	int N, temp = 0, min = 4000, max = -4000, maxFreq = 0, maxIdx = 0;
	int sum = 0;
	vector<int> array;
	vector<int> sameFreq;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		sum += temp;
		if (min > temp) min = temp;
		if (max < temp) max = temp;
		frequency[temp + 4000]++;		//- 값을 고려해서 숫자 자리에 +4000, -4000~4000을 0~8000자리로 옮겨줌
		array.push_back(temp);
	}
	sort(array.begin(), array.end());		//정렬

	//산술평균
	printf("%d\n", (int)round((float)sum / N));
	//중앙값
	printf("%d\n", array[N / 2]);

	if (N > 1) {
		//최빈값
		for (int i = 0; i < N; i++) {		//최빈값 조회
			if (frequency[array[i] + 4000] > maxFreq) {
				sameFreq.clear();
				maxFreq = frequency[array[i] + 4000];
				maxIdx = i;
				sameFreq.push_back(maxIdx);
			}
			else if (frequency[array[i] + 4000] == maxFreq) {		//최빈값이 같은 경우
				if (array[maxIdx] != array[i]) {		//같은 값인 경우 제외
					sameFreq.push_back(i);
				}
			}
			sort(sameFreq.begin(), sameFreq.end());		//정렬
		}
		if (sameFreq.size() > 1)	printf("%d\n", array[sameFreq[1]]);
		else
			printf("%d\n", array[maxIdx]);
	}
	else {		//비교 대상이 1개인 경우
		//최빈값
		printf("%d\n", array[0]);
	}
	//범위
	printf("%d\n", max - min);
	return 0;
}