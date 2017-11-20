all: CDH.c 
	gcc -o hello CDH.c
	./hello
	$ sudo make clean

clean: 
	$(RM) hello