CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: Graph
	./Graph

Graph: obj obj/main.o  obj/AdvancedStopwatch.o obj/Stopwatch.o
	g++ -Wall -pedantic -std=c++0x -o Graph obj/main.o obj/AdvancedStopwatch.o obj/Stopwatch.o

obj:
	mkdir ./obj

obj/Stopwatch.o: src/Stopwatch.cpp 
	g++ -c ${CXXFLAGS} -o obj/Stopwatch.o src/Stopwatch.cpp

obj/AdvancedStopwatch.o: src/AdvancedStopwatch.cpp 
	g++ -c ${CXXFLAGS} -o obj/AdvancedStopwatch.o src/AdvancedStopwatch.cpp

obj/main.o: src/main.cpp inc/Graph.hh inc/Graph_Test.hh inc/BList.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o Graph core
