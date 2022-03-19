all:gen real
gen:generalEx.o
	g++ -std=c++11 -o gen generalEx.o
generalEx.o: generalEx.cpp DTnode.h
	g++ -std=c++11 -c generalEx.cpp
real: worldEx.o
	g++ -std=c++11 -o real worldEx.o
worldEx.o: worldEx.cpp enemy.h player.h
	g++ -std=c++11 -c worldEx.cpp
clean:
	rm -f *o
	rm -f worldEx
	rm -f generalEx
