CC = gcc

FLAGS = `pkg-config --libs --cflags glib-2.0`

ex_compile: ex_compile.c
	gcc -o ex_compile ex_compile.c $(FLAGS)

word_count: word_count.c
	gcc -o word_count word_count.c $(FLAGS)

