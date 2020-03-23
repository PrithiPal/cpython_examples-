
FLAGS=-g -Wall

executable : 
	gcc $(FLAGS) cached_fib.c -o cached_fib.o
