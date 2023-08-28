%{
    #include <stdio.h>
    #include <string.h>
    #include "A5_36.h"
    #include "A5_36.tab.h"
    extern FILE *yyin;
    #define WHITESPACES 1000
    #define MULTILINE_COMMENT 1001
    #define SINGLELINE_COMMENT 1002
%}

/* Regular Expression Definitions */

/* COMMENT*/
%option noyywrap
MULTILINE_COMMENT "/*"[^*]*([*]+[^(/|*)][^*]*)*[*]+"/"
SINGLELINE_COMMENT "//"[^\n]*


/* KEYWORDS:*/
KEYWORD "char"|"else"|"for"|"if"|"int"|"return"|"void"
CHAR "char"
ELSE "else"
FOR "for"
IF "if"
INT "int"
RETURN "return"
VOID "void"

/*IDENTIFIER*/
IDENTIFIER_NONDIGIT [_A-Za-z]
IDENTIFIER_DIGIT [0-9]
IDENTIFIER {IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{IDENTIFIER_DIGIT})*

/*CONSTANTS*/
NONZERO_DIGIT [1-9]
DIGIT {NONZERO_DIGIT}|[0]
SIGN [+-]
NONZERO_INTEGER_CONST {NONZERO_DIGIT}{DIGIT}*
INTEGER_CONST {NONZERO_INTEGER_CONST}|[0]

ESCAPE_SEQUENCE ["\\"](["\'"]|['\"']|[?]|["\\"]|[a]|[b]|[f]|[n]|[t]|[v])
C_CHAR [^"\'"|"\\"|"\n"]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE {C_CHAR}{C_CHAR}*
CHARACTER_CONST "\'"{C_CHAR_SEQUENCE}"\'"

CONSTANT {INTERGER_CONST}|{CHARACTER_CONST}

/*String Literals*/
S_CHAR [^"\""|"\\"|"\n"]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE {S_CHAR}{S_CHAR}*
STRING_LITERAL "\""{S_CHAR_SEQUENCE}?"\""



/*PUNCTUATORS*/
PUNCTUATOR "["|"]"|"("|")"|"{"|"}"|"->"|"&"|"*"|"+"|"-"|"/"|"%"|"!"|"?"|"<"|">"|"<="|">="|"=="|"!="|"&&"|"||"|"="|":"|";"|","
SQBLT   "["
SQBRT   "]"
RDBLT    "("
RDBRT    ")"
CRBLT   "{"
CRBRT   "}"
PTRARW  "->"
AMPERSOND "&"
MULT    "*"
ADD     "+"
SUB     "-"
DIV     "/"
MOD     "%"
NOT     "!"
QSTMK   "?"
LT      "<"
GT      ">"
LTE     "<="
GTE     ">="
EQUALTO "=="
NOTEQUAL"!="
AND     "&&"
OR      "||"
ASGN    "="
COLN    ":"
SCOLN   ";"
COMMA   ","


/*SPACES*/
WHITESPACES [ \n\t]


/* Definitions of Rules \& Actions */
%%
{MULTILINE_COMMENT}     {}
{SINGLELINE_COMMENT}    {}

{CHAR}      {return  CHAR;}
{ELSE}      {return  ELSE;}
{FOR}       {return  FOR;}
{IF}        {return  IF;}
{INT}       {return  INT;}
{RETURN}    {return  RETURN ;}
{VOID}      {return  VOID;}


{IDENTIFIER} {(yylval.ida).var = strdup(yytext); return IDENTIFIER;}

{INTEGER_CONST}    {yylval.intval = atoi(yytext); return  INTEGER_CONST;}
{CHARACTER_CONST}  {yylval.char_value = yytext[1]; return  CHARACTER_CONST;}

{STRING_LITERAL}   {yylval.str_value = strdup(yytext);return  STRING_LITERAL;}

{SQBRT}            {return SQBRT;}
{SQBLT}            {return SQBLT;}
{RDBRT}            {return RDBRT;}
{RDBLT}            {return RDBLT;}
{CRBLT}            {return CRBLT;}
{CRBRT}            {return CRBRT;}
{PTRARW}           {return PTRARW;}
{AMPERSOND}        {return AMPERSOND;}
{MULT}             {return MULT;}
{ADD}              {return ADD;}
{SUB}              {return SUB;}
{DIV}              {return DIV;}
{MOD}              {return MOD;}
{NOT}              {return NOT;}
{QSTMK}            {return QSTMK;}
{LT}               {return LT;}
{GT}               {return GT;}
{LTE}              {return LTE;}
{GTE}              {return GTE;}
{EQUALTO}          {return EQUALTO;}
{NOTEQUAL}         {return NOTEQUAL;}
{AND}              {return AND;}
{OR}               {return OR;}
{ASGN}             {return ASGN;}
{COLN}             {return COLN;}
{SCOLN}            {return SCOLN;}
{COMMA}            {return COMMA;}
{WHITESPACES}      {}



%%
