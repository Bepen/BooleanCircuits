all: SNAP.c
	gcc -o hello SNAP.c
	./hello
	$ sudo make clean

clean:
	$(RM) hello
