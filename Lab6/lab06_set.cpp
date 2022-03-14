#include<iostream>
#include<stdio.h>
#include<set>
#include<utility>
#include<string>
#include"d_state.h"


int main(){
        stateCity one=stateCity("Maryland","Annapolis");
        stateCity two=stateCity("Colorado","Denver");
        stateCity three=stateCity("Florida","Miami");
        stateCity four=stateCity("Kansas","Kansas City");
        stateCity five=stateCity("New Mexico","Roswell");
        set<stateCity> s;
        s.insert(one);
        s.insert(two);
        s.insert(three);
        s.insert(four);
        s.insert(five);
	std::string searchState;
        
	puts("Lab 06 (Task 3):");
	printf("Enter the state to search for: ");
	getline(std::cin,searchState);
	std::set<stateCity>::iterator found=s.find(searchState);
	if(*found==searchState)
		std::cout<<*found<<" was found in the set.\n";
	else
		std::cout<<searchState<<" was not found in the set.\n";
        return 0;
}

