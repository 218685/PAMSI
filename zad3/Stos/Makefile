CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: Stos
	./Stos

Stos: obj obj/main.o obj/Stos.o  obj/main.o obj/IStack.o
	g++ -Wall -pedantic -std=c++0x -o Stos obj/main.o obj/Stos.o obj/IStack.o

obj:
	mkdir ./obj

obj/IStack.o: src/IStack.cpp inc/IStack.hh
	g++ -c ${CXXFLAGS} -o obj/IStack.o src/IStack.cpp

obj/Stos.o: src/Stos.cpp inc/Stos.hh
	g++ -c ${CXXFLAGS} -o obj/Stos.o src/Stos.cpp

obj/main.o: src/main.cpp inc/Stos.hh inc/IStack.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o Stos
