#include<stdio.h>
#include<iostream>

template <typename any>
void swap(any* A, int val1, int val2){
        int tmp=A[val1];
        A[val1]=A[val2];
        A[val2]=tmp;
}

template <typename any>
void printArr(any* A,int len){
        for(int i=0;i<len;i++)
                std::cout<<A[i]<<" ";
        puts("");
}
template <typename any>
bool isSorted(any* A, int len){
	for(int i=0;i<len-1;i++){
		if(A[i]>A[i+1])
			return false;
	}
	return true;
}

template <typename any>
void deSelsort(any* A,int len){
	int min=0;
	int max=0;
        for(int i=0;i<len/2;i++){
                int end=len-i-1;
                min=i;
                max=end;
                for(int j=i+1;j<end;j++){
                        if(A[j]<A[min])
                        	min=j;
			if(A[j]>A[max])
				max=j;
		}
		swap(A,i,min);
                swap(A,end,max);
		if(len<30){
			printf("Rotation %d:\n",i+1);
			printArr(A,len);
		}
        }
	if(isSorted(A,len))
		puts("Sorted Sucessfully!");
	else
		puts("Failed to Sort!");
}
