all:lab10
lab10:lab_10.o
	g++ -std=c++11 -o lab10 lab_10.o
lab10.o:lab_10.cpp d_graph.h
	g++ -std=c++11 -c lab_10.cpp
clean:
	rm -f *o
	rm -f lab_10
