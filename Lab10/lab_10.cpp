#include<iostream>
#include<stdio.h>
#include<fstream>
#include<utility>
#include<set>
#include<list>
#include"d_graph.h"
#include"d_util.h"

int main(){
	graph<char> graphB;
	list<char> dfsList;
	char input;
	graphB.insertVertex('A');
	graphB.insertVertex('B');
	graphB.insertVertex('C');
	graphB.insertVertex('D');
	graphB.insertVertex('E');
	graphB.insertVertex('F');
	
	ifstream fileB;
	fileB.open("graphB.dat",std::fstream::in);
	while (fileB){
		char v1,v2;
		int w;
		fileB>>v1;
		fileB>>v2;
		fileB>>w;
		graphB.insertEdge(v1,v2,w);
	}
	fileB.close();
	std::cout<<graphB;
	puts("Lab 10:");
	printf("Pick a Vertex to traverse from in graph B: ");
	std::cin>>input;

	printf("BFS from %c:\n",input);
	set<char> bOut=bfs(graphB,input);
	writeContainer(bOut.begin(),bOut.end());
	puts("");

	printf("DFS(Reverse Order):\n");
	dfs(graphB,dfsList);
	writeContainer(dfsList.begin(),dfsList.end());
	puts("");
	return 0;
}
