CC = g++
CFLAGS = -Wall -std=c++14

test: main.o gmap.o
	$(CC) $(CFLAGS) -o test main.o gmap.o
	
main.o: main.cpp gmap.hpp
	$(CC) $(CFAGS) -c main.cpp
	
gmap.o: gmap.cpp gmap.hpp
	$(CC) $(CFAGS) -c gmap.cpp

clean:
	rm *.o 