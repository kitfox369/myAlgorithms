//https://sihyungyou.github.io/baekjoon-1436/ 참고
#include<iostream>
using namespace std;

int main()
{
	int N=0, i=666,count=0;
	bool flag;

	scanf("%d", &N);

	while (count != N) {	//666부터 i++하면서 count가 N번까지 도달하기 전까지 돌아감
		int temp = i;
		flag = false;

		while (temp != 0) {
			if (temp%1000==666) {		//666이 존재할 경우 break 해서 while문을 빠져나옴
				flag = true;
				break;
			}
			temp /= 10;
		}

		if (flag) count++;		//만약 숫자에 666이 들어가 있다면
		i++;			
	}

	printf("%d", i-1);
	
	return 0;
}