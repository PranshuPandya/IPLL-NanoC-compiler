/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_A6_36_TAB_H_INCLUDED
# define YY_YY_A6_36_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    IF = 261,                      /* IF  */
    INT = 262,                     /* INT  */
    RETURN = 263,                  /* RETURN  */
    VOID = 264,                    /* VOID  */
    IDENTIFIER = 265,              /* IDENTIFIER  */
    INTEGER_CONST = 266,           /* INTEGER_CONST  */
    CHARACTER_CONST = 267,         /* CHARACTER_CONST  */
    STRING_LITERAL = 268,          /* STRING_LITERAL  */
    SQBRT = 269,                   /* SQBRT  */
    SQBLT = 270,                   /* SQBLT  */
    RDBRT = 271,                   /* RDBRT  */
    RDBLT = 272,                   /* RDBLT  */
    SUB = 273,                     /* SUB  */
    ADD = 274,                     /* ADD  */
    MULT = 275,                    /* MULT  */
    DIV = 276,                     /* DIV  */
    CRBLT = 277,                   /* CRBLT  */
    CRBRT = 278,                   /* CRBRT  */
    PTRARW = 279,                  /* PTRARW  */
    AMPERSOND = 280,               /* AMPERSOND  */
    MOD = 281,                     /* MOD  */
    NOT = 282,                     /* NOT  */
    QSTMK = 283,                   /* QSTMK  */
    LT = 284,                      /* LT  */
    GT = 285,                      /* GT  */
    LTE = 286,                     /* LTE  */
    GTE = 287,                     /* GTE  */
    EQUALTO = 288,                 /* EQUALTO  */
    NOTEQUAL = 289,                /* NOTEQUAL  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    ASGN = 292,                    /* ASGN  */
    COLN = 293,                    /* COLN  */
    SCOLN = 294,                   /* SCOLN  */
    COMMA = 295                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "A6_36.y"

    int intval;
    char char_value;
    char* str_value;

    int num_para;

    quad_ops uop;

    SymbolTableEntry *ste;
    Expression *exp;
    Array* arr;
    id_attr ida;
    Statement * smt;
    typeNode* tpn;

#line 121 "A6_36.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_A6_36_TAB_H_INCLUDED  */
