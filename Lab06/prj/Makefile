CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: HashTab
	./HashTab 

HashTab: obj obj/main.o obj/HashTab.o obj/AdvancedStopwatch.o obj/Stopwatch.o
	g++ -Wall -pedantic -std=c++0x -o HashTab obj/main.o obj/HashTab.o obj/AdvancedStopwatch.o obj/Stopwatch.o

obj:
	mkdir ./obj

obj/Stopwatch.o: src/Stopwatch.cpp 
	g++ -c ${CXXFLAGS} -o obj/Stopwatch.o src/Stopwatch.cpp

obj/AdvancedStopwatch.o: src/AdvancedStopwatch.cpp 
	g++ -c ${CXXFLAGS} -o obj/AdvancedStopwatch.o src/AdvancedStopwatch.cpp

obj/SList.o: src/SList.cpp 
	g++ -c ${CXXFLAGS} -o obj/SList.o src/SList.cpp

obj/HashTab.o: src/HashTab.cpp 
	g++ -c ${CXXFLAGS} -o obj/HashTab.o src/HashTab.cpp

obj/main.o: src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o HashTab
