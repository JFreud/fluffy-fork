all: fork.c
	gcc -o fork fork.c
run: all
	./fork
	
