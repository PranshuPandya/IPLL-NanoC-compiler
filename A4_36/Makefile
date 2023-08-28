# Makefile


A4_36:		bison.o lex.o main.o
		gcc bison.o lex.o main.o -o A4_36 -lm

bison.o:	A4_36.tab.c
		gcc -c A4_36.tab.c -o bison.o

A4_36.tab.c:	A4_36.y
		bison -d -v A4_36.y
		
lex.o:		lex.yy.c
		gcc -c lex.yy.c -o lex.o

lex.yy.c:	A4_36.l
		flex A4_36.l


main.o:		main.c
		gcc -c main.c -o main.o


clean:
	rm -f *.o *~ lex.yy.c A4_36.tab.c A4_36.tab.h A4_36

