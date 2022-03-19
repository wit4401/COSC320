#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"binSearch.h"
#include"deSelsort.h"

int main(){
	srand(time(0));
	int sumFailCom=0;
	int successTotal=0;
	const int ARRSIZE=10000;
	const int RANDOMLIMIT=99999;
	const int RANDOMVALUES=10000;
	int arr[ARRSIZE];

	for (int i=0;i<ARRSIZE;i++)
		arr[i]=rand()%RANDOMLIMIT+1;
	printf("Lab 02: Search Algorithms\nArray was ");
	deSelsort(arr,ARRSIZE);
	
	for (int i=0;i<RANDOMVALUES;i++){
		int val=rand()%RANDOMLIMIT+1;
		if(binSearch(arr,0,ARRSIZE-1,val))
			successTotal++;
		else
			sumFailCom++;
	}
	printf("\n%d of %d failed searches.\n",sumFailCom,RANDOMVALUES);
	printf("%d of %d successful searches.\n",successTotal,RANDOMVALUES);
	puts("End of program...");
}
