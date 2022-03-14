#include<iostream>
#include<stdio.h>
#include<map>
#include<utility>

int main(){
	std::string state, city;
	std::map<std::string,std::string> m;
	m.insert(std::pair<std::string,std::string>("Ohio","Columbus"));
	m.insert(std::pair<std::string,std::string>("Nevada","Las Vegas"));
	m.insert(std::pair<std::string,std::string>("California","Los Angeles"));
	m.insert(std::pair<std::string,std::string>("Texas","Dallas"));
	m.insert(std::pair<std::string,std::string>("Maryland","Columbia"));
	std::string searchState;

	puts("Lab 06 (Task 4):");
	printf("Enter the state to search for: ");
        getline(std::cin,searchState);
	std::map<std::string,std::string>::iterator found=m.find(searchState);
	if(found->first==searchState)
		std::cout<<found->second<<", "<<found->first<<" was found in the map.\n";
	else
		std::cout<<searchState<<" was not found in the map.\n";
	return 0;
}
