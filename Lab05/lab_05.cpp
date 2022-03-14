#include<stdio.h>
#include<iostream>
#include<utility>
#include"int.h"
#include"d_except.h"
#include"d_stree.h"
#include"d_random.h"
#include"d_stiter.h"

int main(){
	stree<integer> tree;
	randomNumber rand;
	const int NUMCOUNT = 10000;

	puts("Lab 05:");
	for(int i=0;i<NUMCOUNT;i++){
		integer num = integer(rand.random(7));
		if(tree.size()==0||!(tree.find(num).nodePtr->nodeValue==num))
			tree.insert(num);
		else
			tree.find(num).nodePtr->nodeValue.incCount();	
	}
	tree.displayTree(2);
	puts("");
	return 0;
}
