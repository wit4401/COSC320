#include<stdio.h>

template <typename any>
bool binSearch(any* A,int begin, int end,any val){
    if(end>-1&&begin>-1&&end>=begin){
	int count=0;
	while(begin<=end){
		int mid=begin+(end-begin)/2;
		if(A[mid]==val){
			count++;
			printf("Found value after %d iterations.\n",count);
			return true;
		}
		if(A[mid]>val)
			end=mid-1;
		else
			begin=mid+1;
		count++;
	}
	printf("Value not found after %d iterations.\n",count);
	return false;	
    }
}
