#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"preqrec.h"
#include"d_pqueue.h"

int main(){
	miniPQ<procReqRec> mpq;
	srand(time(0));
	mpq.push(procReqRec("Process A",rand()%40));
	mpq.push(procReqRec("Process B",rand()%40));
	mpq.push(procReqRec("Process C",rand()%40));
	mpq.push(procReqRec("Process D",rand()%40));
	mpq.push(procReqRec("Process E",rand()%40));
	mpq.push(procReqRec("Process F",rand()%40));
	mpq.push(procReqRec("Process G",rand()%40));
	mpq.push(procReqRec("Process H",rand()%40));
	mpq.push(procReqRec("Process I",rand()%40));
	mpq.push(procReqRec("Process J",rand()%40));
	puts("Lab 08:");
	while(mpq.size()>0){
		std::cout<<mpq.top();
		mpq.pop();
	}	
	return 0;
}
