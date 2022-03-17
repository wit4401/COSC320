all:lab09
lab09:lab_09.o
	g++ -std=c++11 -o lab09 lab_09.o
lab09.o:lab_09.cpp d_graph.h
	g++ -std=c++11 -c lab_09.cpp
clean:
	rm -f *o
	rm -f lab_09
