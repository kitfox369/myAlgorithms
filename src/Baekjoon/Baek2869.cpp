#include<iostream>
#include<string>
using namespace std;

int main() {
	int A=0,B=0,V=0;
	scanf("%d %d %d", &A,&B,&V);

	printf("%d", (V-B-1) / (A - B)+1);

	return 0;
}