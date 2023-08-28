%{
#include <math.h>
#include <stdio.h>
int yylex (void);
int yyerror (char const *s);
#define YYDEBUG 1
extern char *yytext;
extern int yylineno;
%}

/* Bison declarations. */

%token CHAR
%token ELSE
%token FOR
%token IF
%token INT
%token RETURN
%token VOID

%token IDENTIFIER
%token INTEGER_CONST
%token CHARACTER_CONST
%token STRING_LITERAL
token SQBRT
%token SQBLT
%token RDBRT
%token RDBLT
%token SUB
%token ADD
%token MULT
%token DIV
%token CRBLT
%token CRBRT
%token PTRARW
%token AMPERSOND
%token MOD
%token NOT
%token QSTMK
%token LT
%token GT
%token LTE
%token GTE
%token EQUALTO
%token NOTEQUAL
%token AND
%token OR
%token ASGN
%token COLN
%token SCOLN
%token COMMA

%start translation_unit

%% /* The grammar follows. */

primary_expression:
    IDENTIFIER  
    |INTEGER_CONST 
    |CHARACTER_CONST 
    |STRING_LITERAL 
    |RDBLT expression RDBRT 
    ;

postfix_expression:
    primary_expression
    |postfix_expression SQBLT expression SQBRT
    |postfix_expression RDBLT argument_expression_list_opt RDBRT
    |postfix_expression PTRARW IDENTIFIER
    ;

argument_expression_list_opt:
    argument_expression_list
    |
    ;

argument_expression_list:
    assignment_expression
    |argument_expression_list COMMA assignment_expression
    ;

unary_expression:
    postfix_expression
    |unary_operator unary_expression

unary_operator:
    AMPERSOND
    |MULT
    |ADD
    |SUB
    |NOT
    ;

multiplicative_expression:
    unary_expression
    |multiplicative_expression MULT unary_expression
    |multiplicative_expression DIV unary_expression
    |multiplicative_expression MOD unary_expression
    ;

additive_expression:
    multiplicative_expression
    |additive_expression ADD multiplicative_expression
    |additive_expression SUB multiplicative_expression

relational_expression:
    additive_expression
    |relational_expression LT additive_expression
    |relational_expression GT additive_expression
    |relational_expression LTE additive_expression
    |relational_expression GTE additive_expression
    ;

equality_expression:
    relational_expression
    |equality_expression EQUALTO relational_expression
    |equality_expression NOTEQUAL relational_expression
    ;

logical_AND_expression:
    equality_expression
    | logical_AND_expression AND equality_expression
    ;

logical_OR_expression:
    logical_AND_expression
    |logical_OR_expression OR logical_AND_expression
    ;

conditional_expression:
    logical_OR_expression
    |logical_OR_expression QSTMK expression COLN conditional_expression
    ;

assignment_expression:
    conditional_expression
    |unary_expression ASGN assignment_expression
    ;

expression:
    assignment_expression
    ;

declaration:
    type_specifier init_declarator SCOLN
    ;

expression_opt:
    expression
    |
    ;

init_declarator:
    declarator
    |declarator ASGN initializer
    ;

type_specifier:
    VOID
    |CHAR
    |INT
    ;

declarator:
    pointer_opt direct_declarator
    ;

direct_declarator:
    IDENTIFIER
    |IDENTIFIER SQBLT INTEGER_CONST SQBRT
    |IDENTIFIER RDBLT parameter_list_opt RDBRT
    ;

pointer:
    MULT
    ;

pointer_opt:
    pointer
    |
    ;

parameter_list:
    parameter_declaration
    |parameter_list COMMA parameter_declaration
    ;

parameter_list_opt:
    parameter_list
    |
    ;

parameter_declaration:
    type_specifier pointer_opt identifier_opt
    ;

initializer:
    assignment_expression
    ;

statement:
    compound_statement
    |expression_statement
    |selection_statement
    |iteration_statement
    |jump_statement
    ;

compound_statement:
    CRBLT block_item_list_opt CRBRT
    ;

block_item_list:
    block_item
    |block_item_list block_item
    ;
    
block_item_list_opt:
    block_item_list
    |
    ;

block_item:
    declaration
    |statement
    ;

expression_statement:
    expression_opt SCOLN
    ;

selection_statement:
    IF RDBLT expression RDBRT statement
    |IF RDBLT expression RDBRT statement ELSE statement
    ;

iteration_statement:
    FOR RDBLT expression_opt SCOLN expression_opt SCOLN expression_opt RDBRT statement
	;

jump_statement:
    RETURN expression_opt SCOLN
    ;

translation_unit:
    external_declaration 
    |translation_unit  external_declaration
    ;

external_declaration:
    function_definition
	|declaration
	;

function_definition:
    type_specifier declarator compound_statement
    ;



identifier_opt:
    IDENTIFIER
    |
    ;

%%

int yyerror(char const *s) {
    printf("error at %d",yylineno);
}


