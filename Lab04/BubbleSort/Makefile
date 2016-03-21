CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: BubbleSort
	./BubbleSort

BubbleSort: obj obj/main.o obj/Tab.o 
	g++ -Wall -pedantic -std=c++0x -o BubbleSort obj/main.o obj/Tab.o 

obj:
	mkdir ./obj

obj/Tab.o: src/Tab.cpp inc/Tab.hh
	g++ -c ${CXXFLAGS} -o obj/Tab.o src/Tab.cpp

obj/main.o: src/main.cpp inc/Tab.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o BubbleSort
