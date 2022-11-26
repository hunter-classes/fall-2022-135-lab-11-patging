#Patrick Ging Makefile

main: main.o network.o profile.o
	g++ -o main -std=c++11 main.o network.o profile.o

tests: tests.o network.o profile.o
	g++ -o tests -std=c++11 tests.o network.o profile.o

clean:
	rm a.out tests main *.o

#.o files

main.o: main.cpp profile.cpp network.cpp profile.h network.h
	g++ -c -std=c++11 main.cpp profile.cpp network.cpp

tests.o: doctest.h tests.cpp profile.cpp network.cpp profile.h network.h
	g++ -c -std=c++11 tests.cpp profile.cpp network.cpp

network.o: profile.cpp network.cpp profile.h network.h
	g++ -c -std=c++11 profile.cpp network.cpp

profile.o: profile.cpp profile.h
	g++ -c -std=c++11 profile.cpp

