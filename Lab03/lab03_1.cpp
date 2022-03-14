#include<stdio.h>
#include"d_tnodel.h"
#include"d_tnode.h"
#include"countOneChild.h"

int main(){
	tnode<char> *tree1,*b,*c,*d,*e,*f,*g;
	g=new tnode<char> ('G',(tnode<char> *)NULL,(tnode<char> *)NULL);
	f=new tnode<char> ('F',(tnode<char> *)NULL,(tnode<char> *)NULL);
	e=new tnode<char> ('E',(tnode<char> *)NULL,g);
	d=new tnode<char> ('D',(tnode<char> *)NULL,(tnode<char> *)NULL);
	c=new tnode<char> ('C',e,f);
	b=new tnode<char> ('B',d,(tnode<char> *)NULL);
	tree1=new tnode<char> ('A',b,c);
	
	puts("Lab 3 Task 1: countOneChild() function");
	puts("-------");
	puts("Tree 1|");
	puts("-------");
	printf("Depth: %d\n",depth(tree1));
	puts("Incomplete Tree\n----------------------");
	displayTree(tree1,1);
	printf("Interior Nodes w/ One Child: %d\n",countOneChild(tree1));

	tnode<char>* tree2=buildTree(0);
	puts("-------");
        puts("Tree 2|");
        puts("-------");
        printf("Depth: %d\n",depth(tree2));
        puts("Incomplete Tree\n----------------------");
        displayTree(tree2,1);
        printf("Interior Nodes w/ One Child: %d\n",countOneChild(tree2));

	tnode<char>* tree3=buildTree(1);
        puts("-------");
        puts("Tree 3|");
        puts("-------");
        printf("Depth: %d\n",depth(tree3));
        puts("Incomplete Tree\n----------------------");
        displayTree(tree3,4);
        printf("Interior Nodes w/ One Child: %d\n",countOneChild(tree3));
	return 0;
}
