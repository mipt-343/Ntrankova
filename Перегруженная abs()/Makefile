all: main.exe

main.exe: main.o lib.o
	g++ main.o lib.o -o main.exe

main.o: main.cpp lib.h
	g++ -c main.cpp

lib.o: lib.cpp lib.h
	g++ -c lib.cpp