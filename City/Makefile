all: main

main: City.o Industrial.o Leisure.o Residential.o Road.o Cell.o main.o
	g++ -o main.exe City.o Industrial.o Leisure.o Residential.o Road.o Cell.o main.o
	
City.o: City.cpp City.h
	g++ -c City.cpp

Industrial.o: Industrial.cpp Industrial.h
	g++ -c Industrial.cpp

Leisure.o: Leisure.cpp Leisure.h
	g++ -c Leisure.cpp

Residential.o: Residential.cpp Residential.h
	g++ -c Residential.cpp

Road.o: Road.cpp Road.h
	g++ -c Road.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp
	
main.o: main.cpp
	g++ -c main.cpp
