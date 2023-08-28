#include <stdio.h>
extern char *yytext;
int yywrap() {}
int main()
{
    int token;
    while (token = yylex())
    {
        switch (token)
        {
        case MULTILINE_COMMENT:
        {
            printf("<COMMENT, %d, %s>\n", MULTILINE_COMMENT, yytext);break;
        }
        case SINGLELINE_COMMENT:
        {
            printf("<COMMENT, %d, %s>\n", SINGLELINE_COMMENT, yytext);break;
        }

        case CHAR:
        {
            printf("<KEYWORD, %d, char>\n", CHAR);break;
        }
        case ELSE:
        {
            printf("<KEYWORD, %d, else>\n", ELSE);break;
        }
        case FOR:
        {
            printf("<KEYWORD, %d, for>\n", FOR);break;
        }
        case IF:
        {
            printf("<KEYWORD, %d, if>\n", IF);break;
        }
        case INT:
        {
            printf("<KEYWORD, %d, int>\n", INT);break;
        }
        case RETURN:
        {
            printf("<KEYWORD, %d, return>\n", RETURN);break;
        }
        case VOID:
        {
            printf("<KEYWORD, %d, void>\n", VOID);break;
        }

        case IDENTIFIER:
        {
            printf("<ID, %d, %s>\n", IDENTIFIER, yytext);break;
        }

        case INTEGER_CONST:
        {
            printf("<INTEGER CONSTANT, %d, %s>\n", INTEGER_CONST, yytext);break;
        }
        case CHARACTER_CONST:
        {
            printf("<CHARACTER CONSTANT, %d, %s>\n", CHARACTER_CONST, yytext);break;
        }

        case STRING_LITERAL:
        {
            printf("<STRING_LITERAL, %d, %s>\n", STRING_LITERAL, yytext);break;
        }

        case SQBRT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", SQBRT, yytext);break;
        }
        case SQBLT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", SQBLT, yytext);break;
        }
        case RDBRT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", RDBRT, yytext);break;
        }
        case RDBLT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", RDBLT, yytext);break;
        }
        case CRBLT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", CRBLT, yytext);break;
        }
        case CRBRT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", CRBRT, yytext);break;
        }
        case PTRARW:
        {
            printf("<PUCNTUATOR, %d, %s>\n", PTRARW, yytext);break;
        }
        case AMPERSOND:
        {
            printf("<PUCNTUATOR, %d, %s>\n", AMPERSOND, yytext);break;
        }
        case MULT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", MULT, yytext);break;
        }
        case ADD:
        {
            printf("<PUCNTUATOR, %d, %s>\n", ADD, yytext);break;
        }
        case SUB:
        {
            printf("<PUCNTUATOR, %d, %s>\n", SUB, yytext);break;
        }
        case DIV:
        {
            printf("<PUCNTUATOR, %d, %s>\n", DIV, yytext);break;
        }
        case MOD:
        {
            printf("<PUCNTUATOR, %d, %s>\n", MOD, yytext);break;
        }
        case NOT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", NOT, yytext);break;
        }
        case QSTMK:
        {
            printf("<PUCNTUATOR, %d, %s>\n", QSTMK, yytext);break;
        }
        case LT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", LT, yytext);break;
        }
        case GT:
        {
            printf("<PUCNTUATOR, %d, %s>\n", GT, yytext);break;
        }
        case LTE:
        {
            printf("<PUCNTUATOR, %d, %s>\n", LTE, yytext);break;
        }
        case GTE:
        {
            printf("<PUCNTUATOR, %d, %s>\n", GTE, yytext);break;
        }
        case EQUALTO:
        {
            printf("<PUCNTUATOR, %d, %s>\n", EQUALTO, yytext);break;
        }
        case NOTEQUAL:
        {
            printf("<PUCNTUATOR, %d, %s>\n", NOTEQUAL, yytext);break;
        }
        case AND:
        {
            printf("<PUCNTUATOR, %d, %s>\n", AND, yytext);break;
        }
        case OR:
        {
            printf("<PUCNTUATOR, %d, %s>\n", OR, yytext);break;
        }
        case ASGN:
        {
            printf("<PUCNTUATOR, %d, %s>\n", ASGN, yytext);break;
        }
        case COLN:
        {
            printf("<PUCNTUATOR, %d, %s>\n", COLN, yytext);break;
        }
        case SCOLN:
        {
            printf("<PUCNTUATOR, %d, %s>\n", SCOLN, yytext);break;
        }
        case COMMA:
        {
            printf("<PUCNTUATOR, %d, %s>\n", COMMA, yytext);break;
        }

        }
    }
    // yylex(); /* Flex Engine */
    return 0;
}