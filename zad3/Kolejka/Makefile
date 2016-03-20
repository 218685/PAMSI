CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: Kolejka
	./Kolejka

Kolejka: obj obj/main.o obj/Kolejka.o  obj/main.o obj/IQueue.o
	g++ -Wall -pedantic -std=c++0x -o Kolejka obj/main.o obj/Kolejka.o obj/IQueue.o

obj:
	mkdir ./obj

obj/IQueue.o: src/IQueue.cpp inc/IQueue.hh
	g++ -c ${CXXFLAGS} -o obj/IQueue.o src/IQueue.cpp

obj/Kolejka.o: src/Kolejka.cpp inc/Kolejka.hh
	g++ -c ${CXXFLAGS} -o obj/Kolejka.o src/Kolejka.cpp

obj/main.o: src/main.cpp inc/Kolejka.hh inc/IQueue.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o Kolejka
