keywest: main.o stackobj.o stack.o
		g++ main.o stackobj.o stack.o -o keywest -l curses
main.o: main.cpp stackobj.h stack.h
		g++ -c main.cpp
stackobj.o: stackobj.cpp stackobj.h
		g++ -c stackobj.cpp
stack.o: stack.cpp stack.h
		g++ -c stack.cpp
debug:
		g++ main.cpp stackobj.cpp stack.cpp -g -o debug -l curses
clean:
		rm -f *.o test
