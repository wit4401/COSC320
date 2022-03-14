all:program
program:lab02.o
	g++ -std=c++11 -o program lab02.o
lab02.o:lab02.cpp binSearch.h deSelsort.h
	g++ -std=c++11 -c lab02.cpp
clean:
	rm -f *.o
	rm -f lab02
