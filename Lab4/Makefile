all: program
program: lab_04.o
	g++ -std=c++11 -o program lab_04.o
lab_04.o: lab_04.cpp d_tnode.h d_tnodel.h d_expsym.h d_except.h inf2pstf.h
	g++ -std=c++11 -c lab_04.cpp
clean:
	rm -f *.o
	rm -f lab_04
