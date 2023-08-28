#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yydebug;
extern int yylineno;

int yylex(void);
int yyparse(void);
int yywrap() {}
int main(int argc, char **argv)
{
    yydebug = 1;
    if (argc > 1)
    {
        FILE *file;
        file = fopen(argv[1], "r");

        if (!file)
        {
            printf("could not open %s", argv[1]);
            exit(1);
        }

        yyin = file;
    }

    int res = yyparse();
    if (res != 0)
    {
        printf("\nSome Error Occured!\n");
    }
    else
    {
        printf("\nParsing Succesfull.\n");
    }
}
