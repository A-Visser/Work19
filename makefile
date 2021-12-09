all: create process

create: create.o
	gcc -o create create.o

process: process.o
	gcc -o process process.o

process.o: process.c
	gcc -c process.c

create.o: create.c
	gcc -c create.c

clean:
	rm *.o
	rm create
	rm process
	rm *.pipe
