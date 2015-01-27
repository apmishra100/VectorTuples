VectorTuples.out : VectorTuples.o
	g++ -ansi -g -Wall -std=c++11 -o VectorTuples.out VectorTuples.o

VectorTuples.o : VectorTuples.cpp
	g++ -ansi -g -Wall -std=c++11 -c VectorTuples.cpp

clean : 
	rm -f VectorTuples.out VectorTuples.o
