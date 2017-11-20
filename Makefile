all: CDH.c 
	gcc -o hello CDH.c
	./hello

clean: 
	$(RM) hello