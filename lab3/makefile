all: a.out

a.out: lex.yy.c 
	gcc lex.yy.c -lfl

lex.yy.c: lab3lexer.l
	flex lab3lexer.l

run: a.out
	./a.out 
