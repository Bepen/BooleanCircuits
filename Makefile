all: NameTimeDay.c
	gcc -o hello NameTimeDay.c
	./hello
	$ sudo make clean

clean:
	$(RM) hello
