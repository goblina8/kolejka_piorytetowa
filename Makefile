CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: projekt1
	./projekt1

projekt1: obj obj/main.o obj/priority_queue.o obj/functions.o
	g++ -Wall -pedantic -std=c++0x -o projekt1 obj/main.o obj/priority_queue.o obj/functions.o -lpthread
	
obj:
	mkdir obj
	
obj/main.o: src/main.cpp inc/priority_queue.hh inc/functions.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/priority_queue.o: src/priority_queue.cpp inc/priority_queue.hh
	g++ -c ${CXXFLAGS} -o obj/priority_queue.o src/priority_queue.cpp

obj/functions.o: src/functions.cpp inc/functions.hh inc/priority_queue.hh
	g++ -c ${CXXFLAGS} -o obj/functions.o src/functions.cpp

clean:
	rm -f obj/*.o projekt1
