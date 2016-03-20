CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: SLista
	./SLista

SLista: obj obj/main.o obj/SLista.o obj/main.o obj/IList.o
	g++ -Wall -pedantic -std=c++0x -o SLista obj/main.o obj/SLista.o obj/IList.o

obj:
	mkdir ./obj

obj/IList.o: src/IList.cpp inc/IList.hh
	g++ -c ${CXXFLAGS} -o obj/IList.o src/IList.cpp

obj/SLista.o: src/SLista.cpp inc/SLista.hh
	g++ -c ${CXXFLAGS} -o obj/SLista.o src/SLista.cpp

obj/main.o: src/main.cpp inc/SLista.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o SLista
