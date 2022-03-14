#include<iostream>
#include<fstream>
#include<stdio.h>
#include<set>
#include<utility>
#include"d_graph.h"

int main(){
	graph<char> graphA;
	graphA.insertVertex('A');
	graphA.insertVertex('B');
	graphA.insertVertex('C');
	graphA.insertVertex('D');
	graphA.insertVertex('E');
	graphA.insertVertex('F');
	std::ifstream fileA;
	fileA.open("graphA.dat",std::fstream::in);
	puts("Lab 09:");
	while(fileA){
		char v1,v2;
		int w;
		fileA>>v1;
		fileA>>v2;
		fileA>>w;
		graphA.insertEdge(v1,v2,w);
	}
	fileA.close();

	graphA.insertEdge('F','D',1);//i
	graphA.eraseVertex('B');//ii
	graphA.eraseEdge('A','D');//iii
	
	//iv
	char input;
	printf("Enter a Vertex(A,C,D,E,F): ");
	std::cin>>input;
	printf("\nNeighbor(s) of %c:\n",input);
	set<char> neighbor=graphA.getNeighbors(input);
	std::set<char>::iterator curr=neighbor.begin();
	if(neighbor.empty())
		std::cout<<"None";
	else{
		for(int i=0;i<neighbor.size();i++){
			std::cout<<*(curr++);
			if (i!=neighbor.size()-1)
				std::cout<<" & ";
		}
	}
	puts("\n");

	graphA.insertVertex('G');//v
	
	//vi
	graphA.insertEdge('G','C',1);
	graphA.insertEdge('G','F',1);
	graphA.insertEdge('D','G',1);
	
	//vii
	std::cout<<"Graph A:"<<std::endl<<graphA;
	return 0;
}
