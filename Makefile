CC = g++
CFLAGS = -Wall -std=c++14

test: main.o gmap.o challenge.o
	$(CC) $(CFLAGS) -o test main.o gmap.o challenge.o
	
main.o: main.cpp gmap.hpp challenge.hpp
	$(CC) $(CFLAGS) -c main.cpp
	
gmap.o: gmap.cpp gmap.hpp
	$(CC) $(CFLAGS) -c gmap.cpp

test_challenge: test_challenge.o challenge.o
	$(CC) $(CFLAGS) -o test_challenge test_challenge.o challenge.o
	
test_challenge.o: test_challenge.cpp challenge.hpp
	$(CC) $(CFLAGS) -c test_challenge.cpp
	
challenge.o: challenge.cpp challenge.hpp
	$(CC) $(CFLAGS) -c challenge.cpp
	
test_die: test_die.o die.o
	$(CC) $(CFLAGS) -o test_die test_die.o die.o
	
test_die.o: test_die.cpp die.hpp
	$(CC) $(CFLAGS) -c test_die.cpp
	
die.o: die.cpp die.hpp
	$(CC) $(CFLAGS) -c die.cpp

clean:
	rm *.o 