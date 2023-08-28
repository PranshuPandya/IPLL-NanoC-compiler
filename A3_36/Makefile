output.txt: a.out A3_36.nc
	./a.out < A3_36.nc > output.txt

a.out: lex.yy.o
		gcc lex.yy.o -lfl
		
lex.yy.o: lex.yy.c
		gcc -c lex.yy.c -lfl
		
lex.yy.c: A3_36.l A3_36.c
	flex A3_36.l A3_36.c

clean:
	rm  a.out lex.yy.c lex.yy.o output.txt