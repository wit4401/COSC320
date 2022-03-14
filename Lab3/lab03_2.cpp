#include<stdio.h>
#include"d_tnodel.h"
#include"d_tnode.h"
#include"max.h"

tnode<int>* buildIntTree(int);

int main(){
	tnode<int>* tree1=buildIntTree(0);
	puts("Lab 03 Task 2: max() function");
	puts("-------");
	puts("Tree 1|");
	puts("-------");
	printf("Depth: %d\n",depth(tree1));
	puts("Complete Tree");
	puts("");
	displayTree(tree1,2);
	printf("Maximum Int: %d\n", max(tree1));
	
	tnode<int>* tree2=buildIntTree(1);
	puts("-------");
	puts("Tree 2|");
	puts("-------");
	printf("Depth: %d\n",depth(tree2));
        puts("Complete Tree");
        puts("");
        displayTree(tree2,2);
	printf("Maximum Int: %d\n", max(tree2));
	return 0;
}

tnode<int>* buildIntTree(int n){
	tnode<int> *root,*b,*c,*d,*e,*f;
	if(n<2&&n>-1){
		switch (n){
			case 0:
				f=new tnode<int>(12,(tnode<int> *)NULL,(tnode<int> *)NULL);
				e=new tnode<int>(48,(tnode<int> *)NULL,(tnode<int> *)NULL);
				d=new tnode<int>(5,(tnode<int> *)NULL,(tnode<int> *)NULL);
				c=new tnode<int>(15,e,f);
				b=new tnode<int>(40,d,(tnode<int> *)NULL);
				root=new tnode<int>(35,b,c);
				break;
			case 1:
                                e=new tnode<int>(23);
                                d=new tnode<int>(8,e,(tnode<int> *)NULL);
                                c=new tnode<int>(9);
                                b=new tnode<int>(10,(tnode<int> *)NULL,d);
                                root=new tnode<int>(30,b,c);
				break;
			default:
				puts("ERROR!");
		}
	}
}
