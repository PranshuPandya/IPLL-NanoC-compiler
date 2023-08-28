%{
    #include <stdio.h>
    #include <string.h>
%}

%{
// COMMENTS
#define SINGLELINE_COMMENT 1
#define MULTILINE_COMMENT 2

// KEYWORD
#define CHAR 3
#define ELSE 4
#define FOR 5
#define IF 6
#define INT 7
#define RETURN  8
#define VOID 9

// IDENTIFIER
#define IDENTIFIER 10

// CONSTANTS
#define INTEGER_CONST 11
#define CHARACTER_CONST 12

// STRING LITERAL
#define STRING_LITERAL 13

// PUNCTUATORS
#define SQBLT 14
#define RDBRT 15
#define RDBLT 16
#define SQBRT 17
#define CRBLT 18
#define CRBRT 19
#define PTRARW 20
#define AMPERSOND 21
#define MULT 22
#define ADD 23
#define SUB 24
#define DIV 25
#define MOD 26
#define NOT 27
#define QSTMK 28
#define LT 29
#define GT 30
#define LTE 31
#define GTE 32
#define EQUALTO 33
#define NOTEQUAL 34
#define AND 35
#define OR 36
#define ASGN 37
#define COLN 38
#define SCOLN 39
#define COMMA 40
#define WHITESPACES 41

%}

/* Regular Expression Definitions */

/* COMMENT*/
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

{MULTILINE_COMMENT}     {return MULTILINE_COMMENT;}
{SINGLELINE_COMMENT}    {return SINGLELINE_COMMENT;}

{CHAR}      {return  CHAR;}
{ELSE}      {return  ELSE;}
{FOR}       {return  FOR;}
{IF}        {return  IF;}
{INT}       {return  INT;}
{RETURN}    {return  RETURN ;}
{VOID}      {return  VOID;}


{IDENTIFIER} {return IDENTIFIER;}

{INTEGER_CONST}    {return  INTEGER_CONST;}
{CHARACTER_CONST}  {return  CHARACTER_CONST;}
{STRING_LITERAL}   {return  STRING_LITERAL;}

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
{WHITESPACES}       {return WHITESPACES;}

%%
