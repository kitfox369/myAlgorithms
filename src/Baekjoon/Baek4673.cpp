#include <iostream>
using namespace std;

void recursiveFunc(int idx,bool array[])
{
	int sum=0;
	if(idx<10000)
	{
		sum+=idx;
		while(idx>0){
			sum+=(idx%10);
			idx/=10;
		}
		if(array[sum]==false&&sum<10000)
			array[sum]=true;
		return recursiveFunc(sum,array);
	}
	else{
		return ;
	}
}

int main() {
	bool array[10000]={false,};
	for(int i=1;i<10000;i++)
	{
		recursiveFunc(i,array);
	}
	for(int i=1;i<10000;i++){
		if(array[i]==false){
			printf("%d\n",i);
		}
	}
	return 0;
}