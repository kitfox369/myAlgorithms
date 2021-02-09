#include<iostream>
#include<string>
using namespace std;

int main() {
	int N=0,quotient=0,rest=0;
	scanf("%d", &N);
	
	while (0 < N) {
		if (N > ++quotient);
		else rest = N;
		N -= quotient;
	}
	
	int different = quotient - rest;
	int idxL=quotient- different, idxR=1+ different;
	if(quotient%2==0)printf("%d/%d", idxL,idxR);
	else printf("%d/%d", idxR, idxL);
	return 0;
}