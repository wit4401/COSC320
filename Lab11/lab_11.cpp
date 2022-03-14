#include<stdio.h>
#include<fstream>
#include<utility>
#include<set>
#include<list>
#include"d_graph.h"
#include"d_util.h"

set<char> restOfVertices(char v,graph<char> g){
    graph<char>::iterator curr = g.begin();
    set<char> vertices;
    for(int i=0;i<g.numberOfVertices();i++){
        if(*curr!=v)
            vertices.insert(*curr);
        curr++;
    }
    return vertices;
}

int main(){
    graph<char> graphB;
	char input;
	graphB.insertVertex('A');
	graphB.insertVertex('B');
	graphB.insertVertex('C');
	graphB.insertVertex('D');
	graphB.insertVertex('E');
	graphB.insertVertex('F');
	list<char> minList[graphB.numberOfVertices()];
    
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
	puts("Lab 11:");
    printf("Pick a Vertex in Graph B: ");
	std::cin>>input;
   
    set<char> verts=restOfVertices(input,graphB);
    int nums[verts.size()];
    std::set<char>::iterator setNum = verts.begin();
    
    int max=0;
    char value;
    for(int i=0;i<verts.size();i++){
        nums[i]=minimumPath(graphB,input,*setNum,minList[i]);
        if(nums[i]>nums[max]){
            max=i;
            value=*setNum;
        }
        setNum++;
    }
    std::cout<<"Largest minimum-path weight:V="<<value<<" & W=";
    std::cout<<nums[max]<<std::endl;
    std::cout<<"Path taken: ";
    writeList(minList[max]," ");
    return 0;
}
