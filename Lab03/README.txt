Task 1:
countOneChild.h
#include"d_tnode.h"

template <typename T>
int countOneChild(tnode<T>* root){
        int val=0;
        if(root->left&&root->right)
                return countOneChild(root->left)+countOneChild(root->right);
        if(root->left)
                return 1+countOneChild(root->left);
        if(root->right)
                return 1+countOneChild(root->right);
        return 0;
}

lab03_1.cpp
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

Output (Task 1):
Lab 3 Task 1: countOneChild() function
-------
Tree 1|
-------
Depth: 3
Incomplete Tree
----------------------
    A
  B      C
D    E    F
        G
Interior Nodes w/ One Child: 2
-------
Tree 2|
-------
Depth: 2
Incomplete Tree
----------------------
    A
B      C
  D  E
Interior Nodes w/ One Child: 2
-------
Tree 3|
-------
Depth: 3
Incomplete Tree
----------------------
                       A
        B                  C
   D             E                  F
             G                  H        I
Interior Nodes w/ One Child: 2

Task 2:
max.h
#include"d_tnode.h"

template<typename T>
T max(tnode<T>* root){
        if(root){
                T rootData=root->nodeValue;
                T left=max(root->left);
                T right=max(root->right);
                if(left>rootData)
                        rootData=left;
                if(right>rootData)
                        rootData=right;
                return rootData;
        }
        else
                return NULL;
}

lab03_2.cpp
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

Output (Task 2):
Lab 03 Task 2: max() function
-------
Tree 1|
-------
Depth: 2
Complete Tree

      35
   40      15
 5      48   12
Maximum Int: 48
-------
Tree 2|
-------
Depth: 3
Complete Tree

         30
10          9
       8
   23
Maximum Int: 30

   

        

