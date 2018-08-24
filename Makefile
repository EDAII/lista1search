CC := gcc
CFLAGS := -W -Wall -pedantic -ansi -lm -Wcomment -std=c99

all:

	$(CC) binary_tree.c helper.c main.c vector_search.c menu.c -o prog $(CFLAGS)

clean:

	rm prog

run:

	./prog