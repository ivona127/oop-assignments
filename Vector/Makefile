all: main

main: Vector.o main.o
	g++ -o main.exe Vector.o main.o
	
Vector.o: Vector.cpp Vector.h
	g++ -c Vector.cpp

main.o: main.cpp
	g++ -c main.cpp
