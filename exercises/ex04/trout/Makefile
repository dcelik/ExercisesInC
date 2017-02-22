main: main.o trout.o util.o trout.h util.h
	gcc main.o trout.o util.o -o main -Wall
trout.o: trout.c trout.h
	gcc -c trout.c -Wall
util.o: util.c util.h
	gcc -c util.c -Wall
main.o: main.c trout.o util.o
	gcc -c main.c -Wall
