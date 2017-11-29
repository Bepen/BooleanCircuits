all: main.c
	gcc -o database main.c -Wall -Werror
	./database
