all: main.c
	gcc -o hello main.c -Wall -Werror
	./hello
	$ sudo make clean

clean:
	$(RM) hello
