# Makefile


A6_36:		bison.o lex.o A6_36.o A6_36_target.o
		g++ bison.o lex.o A6_36.o A6_36_target.o -o A6_36 -lm

bison.o:	A6_36.tab.c
		g++ -c A6_36.tab.c -o bison.o
		

A6_36.tab.c:	A6_36.y
		bison -d -v A6_36.y
		@echo "Parsing Successfull\n"
		
lex.o:		lex.yy.c
		g++ -c lex.yy.c -o lex.o

lex.yy.c:	A6_36.l
		flex A6_36.l
		@echo "Lexical Analysis Successfull\n"

A6_36.o:		A6_36.cpp 
		g++ -c A6_36.cpp -o A6_36.o

A6_36_target.o:		A6_36_target.cpp 
		g++ -c A6_36_target.cpp -o A6_36_target.o
		@echo "nanoC target code generator created \n"

libA6_36_lib.a: A6_36_lib.o
	ar -rcs libA6_36_lib.a A6_36_lib.o
	@echo "required libraries are ready \n"

A6_36_lib.o: A6_36_lib.c myl.h
	gcc -c A6_36_lib.c


clean:
	rm input.s libA6_36_lib.a A6_36_lib.o -f *.o *~ lex.yy.c A6_36.tab.c A6_36.tab.h A6_36

test: A6_36.out libA6_36_lib.a input.c
	@echo "Generating assembly files\n"
	./A6_36 input > output_quads
	@echo "Compiling assembly files\n"
	gcc input.s -L. -lA6_36_lib -no-pie -o test

