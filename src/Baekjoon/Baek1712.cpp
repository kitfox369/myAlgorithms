#include<iostream>
#include<string>
using namespace std;

int main() {
	int fixedCost=0,variableCost=0,productionCost=0;
	int productNum = 1;
	scanf("%d %d %d", &fixedCost,&variableCost,&productionCost);
	if (productionCost <= variableCost) {
		printf("%d", -1);
	}
	else {
		printf("%d", fixedCost/(productionCost-variableCost)+1);
	}
	return 0;
}