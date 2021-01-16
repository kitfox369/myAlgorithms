#include <iostream>
using namespace std;

int main() {
	char unicode;
	scanf("%c",&unicode);
	printf("%d",static_cast<int>(unicode));
	return 0;
}