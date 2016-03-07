#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: Tablica
	./Tablica

Tablica: obj obj/main.o obj/Tab.o
	g++ -Wall -pedantic -std=c++0x -o Tablica obj/main.o obj/Tab.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/IRunnable.hh inc/Tab.hh inc/IStoper.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Tab.o: src/Tab.cpp inc/Tab.hh
	g++ -c ${CXXFLAGS} -o obj/Tab.o src/Tab.cpp

clean:
	rm -f obj/*.o manipulator_3D
