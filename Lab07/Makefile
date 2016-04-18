CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: BinaryTree
	./BinaryTree

BinaryTree: obj obj/main.o obj/BTreeTab.o 
	g++ -Wall -pedantic -std=c++0x -o BinaryTree obj/main.o obj/BTreeTab.o 

obj:
	mkdir ./obj

obj/BTreeTab.o: src/BTreeTab.cpp inc/BTreeTab.hh
	g++ -c ${CXXFLAGS} -o obj/BTreeTab.o src/BTreeTab.cpp

obj/main.o: src/main.cpp inc/BTreeTab.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o BinaryTree
