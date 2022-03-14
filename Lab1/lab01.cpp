#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"deSelsort.h"

int main(){
	int testArr[]={13,5,2,25,47,17,8,21};
	puts("Test Array:");
	printArr(testArr,8);
	deSelsort(testArr,8);
	
	puts("");

	int len=0;
	int* randArr;
	srand(time(0));
	
	while (len<=0||len>=30){
		printf("Please input a size for random integer array between 1-29: ");
		std::cin>>len;
		if(len<=0||len>=30)
			puts("Invalid Length!");
	}
	randArr=new int[len];	
	puts("Random Array:");
	for (int i=0;i<len;i++)
		randArr[i]=rand()%1000;
	printArr(randArr,len);
	deSelsort(randArr,len);
	delete [] randArr;
	puts("\nEnd of program...");
	return 0;
}
