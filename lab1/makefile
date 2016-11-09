all: expression

expression: expr.o input_token.o error.o BTree.o main.o 
	gcc -o expression expr.o input_token.o error.o BTree.o main.o

main.o: main.c input_token.c expr.c error.c BTree.c
	gcc -c main.c

error.o: error.c error.h 
	gcc -c error.c

input_token.o: input_token.c input_token.h error.h
	gcc -c input_token.c

expr.o: expr.c expr.h input_token.h error.h
	gcc -c expr.c

BTree.o: BTree.c BTree.h input_token.h
	gcc -c BTree.c

clean: 
	rm -rf *.o expression




