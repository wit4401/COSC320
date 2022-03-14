all:lab8
lab8: lab_08.o
	g++ -std=c++11 -o lab8  lab_08.o
lab_08.o:lab_08.cpp preqrec.h d_pqueue.h d_heap.h
	g++ -std=c++11 -c lab_08.cpp
clean:
	rm -f *.o
	rm -f lab_08
