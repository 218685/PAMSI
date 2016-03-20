CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: TestSLista
	./TestSLista 

TestSLista: obj obj/main.o obj/IStoper.o obj/StoperZZapisem.o obj/main.o obj/TestSLista.o obj/SLista.o obj/IList.o
	g++ -Wall -pedantic -std=c++0x -o TestSLista obj/main.o obj/IStoper.o obj/StoperZZapisem.o obj/TestSLista.o obj/SLista.o obj/IList.o

obj:
	mkdir ./obj

obj/IStoper.o: src/IStoper.cpp inc/IStoper.hh
	g++ -c ${CXXFLAGS} -o obj/IStoper.o src/IStoper.cpp

obj/StoperZZapisem.o: src/StoperZZapisem.cpp inc/StoperZZapisem.hh
	g++ -c ${CXXFLAGS} -o obj/StoperZZapisem.o src/StoperZZapisem.cpp

obj/IList.o: src/IList.cpp inc/IList.hh
	g++ -c ${CXXFLAGS} -o obj/IList.o src/IList.cpp

obj/SLista.o: src/SLista.cpp inc/SLista.hh
	g++ -c ${CXXFLAGS} -o obj/SLista.o src/SLista.cpp

obj/TestSLista.o: src/TestSLista.cpp inc/TestSLista.hh
	g++ -c ${CXXFLAGS} -o obj/TestSLista.o src/TestSLista.cpp

obj/main.o: src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o TestSLista
