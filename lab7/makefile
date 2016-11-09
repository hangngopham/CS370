hw7ast.o: hw7ast.c hw7ast.h
	gcc -c hw7ast.c
hw7symtbl.o: hw7symtbl.c hw7symtbl.h
	gcc -c hw7symtbl.c
mem.o: mem.c mem.h
	gcc -c mem.c
lex.yy.c: hw7lexer.l
	flex hw7lexer.l
y.tab.c: hw7parser.y lex.yy.c
	yacc hw7parser.y
y.tab.o: y.tab.c
	gcc -c y.tab.c
myhw8: hw8.gen.codes.c y.tab.o hw7ast.o mem.o hw7symtbl.o 
	gcc -o myhw8 hw8.gen.codes.c y.tab.o hw7ast.o mem.o hw7symtbl.o -lfl -ly
clean: 
	rm -f myhw8 y.tab.o mem.o hw7ast.o hw7symtbl.o y.tab.c lex.yy.c

