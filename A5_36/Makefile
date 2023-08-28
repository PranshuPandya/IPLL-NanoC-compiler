# Makefile


A5_36:		bison.o lex.o A5_36.o
		g++ bison.o lex.o A5_36.o -o A5_36 -lm

bison.o:	A5_36.tab.c
		g++ -c A5_36.tab.c -o bison.o

A5_36.tab.c:	A5_36.y
		bison -d -v A5_36.y
		
lex.o:		lex.yy.c
		g++ -c lex.yy.c -o lex.o

lex.yy.c:	A5_36.l
		flex A5_36.l


A5_36.o:		A5_36.cpp 
		g++ -c A5_36.cpp -o A5_36.o


clean:
	rm -f *.o *~ lex.yy.c A5_36.tab.c A5_36.tab.h A5_36

