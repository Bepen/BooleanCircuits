all: StudentCourse.c
	gcc -o hello StudentCourse.c
	./hello
	$ sudo make clean

clean:
	$(RM) hello
