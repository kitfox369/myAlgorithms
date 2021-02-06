#include<iostream>
#include<string>
using namespace std;

int main() {
	int count = 0, idx = 0,senNum=0;
	char sentence[100] = { " " , };
	bool continuous = true;
	int prevNum = 0;
	scanf("%d", &senNum);
	for (int i = 0; i < senNum; i++) {
		scanf("%s", sentence);
		bool alpha[26] = { false, };
		idx = 0;
		prevNum = 0;
		continuous = true;
		while (idx <= 100 && sentence[idx] != '\0') {
			if ((alpha[sentence[idx] - 97] && prevNum != sentence[idx]&&prevNum!=0)) {
				continuous = false;
				break;
			}
			else {
				if (!alpha[sentence[idx] - 97])
					alpha[sentence[idx] - 97] = true;
				prevNum = sentence[idx];
				idx++;
			}
		}
		if (continuous) count++;
	}
	printf("%d", count);

	return 0;
}