CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: Tablica
	./Tablica

Tablica: obj obj/main.o obj/IStoper.o obj/StoperZZapisem.o obj/IRunnable.o obj/Tab.o obj/TabTest.o obj/main.o
	g++ -Wall -pedantic -std=c++0x -o Tablica obj/main.o obj/Tab.o obj/TabTest.o obj/IStoper.o obj/StoperZZapisem.o obj/IRunnable.o 

obj:
	mkdir ./obj

obj/IStoper.o: src/IStoper.cpp inc/IStoper.hh
	g++ -c ${CXXFLAGS} -o obj/IStoper.o src/IStoper.cpp

obj/StoperZZapisem.o: src/StoperZZapisem.cpp inc/StoperZZapisem.hh
	g++ -c ${CXXFLAGS} -o obj/StoperZZapisem.o src/StoperZZapisem.cpp

obj/IRunnable.o: src/IRunnable.cpp inc/IRunnable.hh
	g++ -c ${CXXFLAGS} -o obj/IRunnable.o src/IRunnable.cpp

obj/Tab.o: src/Tab.cpp inc/Tab.hh
	g++ -c ${CXXFLAGS} -o obj/Tab.o src/Tab.cpp

obj/TabTest.o: src/TabTest.cpp inc/TabTest.hh
	g++ -c ${CXXFLAGS} -o obj/TabTest.o src/TabTest.cpp

obj/main.o: src/main.cpp inc/IRunnable.hh inc/Tab.hh inc/TabTest.hh inc/IStoper.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o Tablica
