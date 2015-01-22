vsort.out : Vector\ Sort.o
	g++ -ansi -g -Wall -std=c++11 -o vsort.out Vector\ Sort.o

Vector\ Sort.o :  Vector\ Sort.cpp
	g++ -ansi -g -Wall -std=c++11 -c Vector\ Sort.cpp

clean :
	rm -f vsort.out Vector\ Sort.o
