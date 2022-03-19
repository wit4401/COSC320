#include<iostream>
#include<stdio.h>
#include<string>
#include"DTnode.h"

//This function goes through the algorithm
template<typename T>
bool decide(node<T>*,int,int,bool,bool);

node<int>* createDT();

int main(){
    bool crim,credit;
    int c,income,years;
    printf("Enter Yearly Income (Enter 1=1000k): ");
    std::cin>>income;
    printf("Enter Years at Current Job: ");
    std::cin>>years;
    printf("Criminal Record (1=Yes 0=No): ");
    std::cin>>c;
    if(c==1)
        crim=true;
    else
        crim=false;
    printf("Credit Card Payments (1=Yes 0=No): ");
    std::cin>>c;
    if(c==1)
        credit=true;
    else
        credit=false;
    
	node<int>* root=createDT();
	if(decide(root,income,years,crim,credit))
        puts("You are most likely eligible for a loan!");
    else
        puts("You are most likely not eligible for a loan...");
	return 0;
}

template <typename T>
bool decide(node<T>* root,int income,int jobLength,bool cr, bool credit){
	if(root->left&&root->right){
		if(root->center&&root->nodeValue==70){
            if(income>root->nodeValue)
                return decide(root->right,income,jobLength,cr,credit);
            else if(income>30)
                return decide(root->center,income,jobLength,cr,credit);
            else
                return decide(root->left,income,jobLength,cr,credit);
        }
        else if(root->center){
           if(jobLength>root->nodeValue)
                return decide(root->right,income,jobLength,cr,credit);
            else if(jobLength>1)
                return decide(root->center,income,jobLength,cr,credit);
            else
                return decide(root->left,income,jobLength,cr,credit);
        }
        else if(root->nodeValue==0){
            if(cr)
                return decide(root->right,income,jobLength,cr,credit);
            else
                return decide(root->left,income,jobLength,cr,credit);
        }
        else{
            if(credit)
                return decide(root->left,income,jobLength,cr,credit);
            else
                return decide(root->right,income,jobLength,cr,credit);
        }
	}
	else{
        if(root->nodeValue==0)
            return false;
        else
            return true;
    }
}

node<int>* createDT(){
    node<int>* n12=new node<int>(0);//n7 (False)
	node<int>* n11=new node<int>(1);//n7 (True)
    
	node<int>* n10=new node<int>(0);//n3 (False)
    node<int>* n9=new node<int>(1);//n3 (True)
    
	node<int>* n8=new node<int>(1);//n2 years>5 (Loan)
	node<int>* n7=new node<int>(-1,n11,NULL,n12);//n2 1<years<5 (Check CC Payments)
	node<int>* n6=new node<int>(0);//n2 years<1 (No Loan)
    
	node<int>* n5=new node<int>(0);//n1 False
	node<int>* n4=new node<int>(1);//n1 True
	
    node<int>* n3=new node<int>(0,n9,NULL,n10);//Criminal Record
	
    node<int>* n2=new node<int>(5,n6,n7,n8);//Years in Current Job
	
    node<int>* n1=new node<int>(0,n4,NULL,n5);//Criminal Record?
	
    node<int>* root=new node<int>(70,n1,n2,n3);//Yearly Income
    return root;
}
