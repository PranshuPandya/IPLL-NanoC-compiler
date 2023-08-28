/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "A5_36.y"

#include "A5_36.h"
int yylex (void);
int yyerror (char const *s);
#define YYDEBUG 1
extern char *yytext;
extern typenode_types cur_type;
// extern yylineno;

#line 81 "A5_36.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "A5_36.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_IDENTIFIER = 10,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONST = 11,             /* INTEGER_CONST  */
  YYSYMBOL_CHARACTER_CONST = 12,           /* CHARACTER_CONST  */
  YYSYMBOL_STRING_LITERAL = 13,            /* STRING_LITERAL  */
  YYSYMBOL_SQBRT = 14,                     /* SQBRT  */
  YYSYMBOL_SQBLT = 15,                     /* SQBLT  */
  YYSYMBOL_RDBRT = 16,                     /* RDBRT  */
  YYSYMBOL_RDBLT = 17,                     /* RDBLT  */
  YYSYMBOL_SUB = 18,                       /* SUB  */
  YYSYMBOL_ADD = 19,                       /* ADD  */
  YYSYMBOL_MULT = 20,                      /* MULT  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_CRBLT = 22,                     /* CRBLT  */
  YYSYMBOL_CRBRT = 23,                     /* CRBRT  */
  YYSYMBOL_PTRARW = 24,                    /* PTRARW  */
  YYSYMBOL_AMPERSOND = 25,                 /* AMPERSOND  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_QSTMK = 28,                     /* QSTMK  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_LTE = 31,                       /* LTE  */
  YYSYMBOL_GTE = 32,                       /* GTE  */
  YYSYMBOL_EQUALTO = 33,                   /* EQUALTO  */
  YYSYMBOL_NOTEQUAL = 34,                  /* NOTEQUAL  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_ASGN = 37,                      /* ASGN  */
  YYSYMBOL_COLN = 38,                      /* COLN  */
  YYSYMBOL_SCOLN = 39,                     /* SCOLN  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_41_then_ = 41,                  /* "then"  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_M = 43,                         /* M  */
  YYSYMBOL_N = 44,                         /* N  */
  YYSYMBOL_primary_expression = 45,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 46,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 47, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 48,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 49,          /* unary_expression  */
  YYSYMBOL_unary_operator = 50,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 51, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 52,       /* additive_expression  */
  YYSYMBOL_relational_expression = 53,     /* relational_expression  */
  YYSYMBOL_equality_expression = 54,       /* equality_expression  */
  YYSYMBOL_logical_AND_expression = 55,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 56,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 57,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 58,     /* assignment_expression  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_declaration = 60,               /* declaration  */
  YYSYMBOL_init_declarator = 61,           /* init_declarator  */
  YYSYMBOL_type_specifier = 62,            /* type_specifier  */
  YYSYMBOL_declarator = 63,                /* declarator  */
  YYSYMBOL_direct_declarator = 64,         /* direct_declarator  */
  YYSYMBOL_PRA = 65,                       /* PRA  */
  YYSYMBOL_pointer = 66,                   /* pointer  */
  YYSYMBOL_parameter_list = 67,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 68,     /* parameter_declaration  */
  YYSYMBOL_initializer = 69,               /* initializer  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_compound_statement = 71,        /* compound_statement  */
  YYSYMBOL_block_item_list = 72,           /* block_item_list  */
  YYSYMBOL_block_item_list_opt = 73,       /* block_item_list_opt  */
  YYSYMBOL_block_item = 74,                /* block_item  */
  YYSYMBOL_expression_statement = 75,      /* expression_statement  */
  YYSYMBOL_selection_statement = 76,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 77,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 78,            /* jump_statement  */
  YYSYMBOL_translation_unit = 79,          /* translation_unit  */
  YYSYMBOL_external_declaration = 80,      /* external_declaration  */
  YYSYMBOL_function_definition = 81,       /* function_definition  */
  YYSYMBOL_changetable_dec = 82,           /* changetable_dec  */
  YYSYMBOL_changetable_def = 83            /* changetable_def  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   124,   132,   150,   161,   172,   195,   202,
     211,   233,   241,   248,   253,   259,   265,   274,   278,   325,
     329,   333,   337,   341,   348,   364,   394,   423,   455,   459,
     475,   494,   498,   517,   537,   557,   580,   584,   606,   631,
     635,   650,   654,   669,   673,   703,   707,   731,   738,   742,
     746,   755,   758,   761,   767,   774,   780,   787,   797,   815,
     835,   844,   848,   851,   863,   876,   884,   890,   898,   905,
     909,   914,   918,   922,   929,   936,   940,   948,   953,   959,
     963,   970,   975,   982,   992,  1006,  1016,  1030,  1037,  1046,
    1047,  1051,  1052,  1056,  1063,  1076
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "ELSE", "FOR",
  "IF", "INT", "RETURN", "VOID", "IDENTIFIER", "INTEGER_CONST",
  "CHARACTER_CONST", "STRING_LITERAL", "SQBRT", "SQBLT", "RDBRT", "RDBLT",
  "SUB", "ADD", "MULT", "DIV", "CRBLT", "CRBRT", "PTRARW", "AMPERSOND",
  "MOD", "NOT", "QSTMK", "LT", "GT", "LTE", "GTE", "EQUALTO", "NOTEQUAL",
  "AND", "OR", "ASGN", "COLN", "SCOLN", "COMMA", "\"then\"", "$accept",
  "M", "N", "primary_expression", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "expression",
  "declaration", "init_declarator", "type_specifier", "declarator",
  "direct_declarator", "PRA", "pointer", "parameter_list",
  "parameter_declaration", "initializer", "statement",
  "compound_statement", "block_item_list", "block_item_list_opt",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "changetable_dec",
  "changetable_def", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,  -142,  -142,  -142,  -142,    -7,    73,  -142,  -142,    42,
    -142,   -27,   -15,  -142,    27,    56,  -142,  -142,    60,  -142,
     170,    57,  -142,  -142,    70,  -142,  -142,  -142,  -142,   170,
    -142,  -142,  -142,  -142,  -142,  -142,    25,    51,   170,    87,
      29,    85,    58,    65,   -13,  -142,  -142,  -142,   116,  -142,
      78,  -142,  -142,    77,   170,   170,    92,   170,  -142,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
      69,    18,    89,   115,   134,  -142,    98,  -142,    -7,  -142,
    -142,    72,    86,  -142,  -142,  -142,  -142,  -142,  -142,     4,
       3,  -142,  -142,   128,   132,   109,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,    87,    87,    29,    29,    29,    29,    85,
      85,  -142,  -142,  -142,   152,   170,  -142,   111,  -142,   119,
     116,  -142,  -142,   147,  -142,    96,  -142,  -142,   170,   170,
     170,   170,  -142,  -142,  -142,  -142,  -142,  -142,  -142,    58,
    -142,    65,   152,   142,   122,   150,  -142,  -142,  -142,   170,
      50,   170,    50,  -142,  -142,  -142,  -142,   151,   164,  -142,
    -142,    50,    50,  -142,  -142
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    52,    53,    51,    92,     0,     0,    89,    91,    56,
      61,     0,    49,    55,     0,     0,     1,    90,     0,    48,
       0,     0,    94,    54,     0,     4,     5,     6,     7,     0,
      22,    21,    20,    19,    23,     9,    17,    24,     0,    28,
      31,    36,    39,    41,    43,    45,    68,    50,    78,    93,
       0,    57,    47,     0,     0,    14,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,    79,     0,    80,
      69,     2,     0,    75,    70,    71,    72,    73,    59,    67,
       0,    62,     8,     0,     0,    13,    15,    12,    46,    25,
      26,    27,    24,    30,    29,    32,    33,    34,    35,    37,
      38,     2,     2,     2,     0,     0,    88,     0,    81,    49,
       0,    74,    65,    66,    58,     0,    10,    11,     0,     0,
       0,     0,     2,     3,    87,    76,    64,    63,    16,    40,
       3,    42,     0,     0,     0,     2,     2,     2,     2,     0,
       0,     0,     0,     3,     3,    44,    85,     0,    83,     2,
       2,     0,     0,    86,    84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,   -95,   -43,  -142,  -142,  -142,  -142,   -33,  -142,    68,
     135,    71,    45,    44,  -142,    33,   -16,   -29,   -46,  -142,
     -42,   100,   161,  -142,    97,  -142,    67,  -142,  -141,   172,
    -142,  -142,    74,  -104,  -142,  -142,  -142,  -142,   179,  -142,
    -142,  -142
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,   120,    70,    35,    36,    94,    95,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    52,    76,     4,    11,
       5,    12,    13,    14,    15,    90,    91,    47,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     6,     7,     8,
      50,    21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    71,    77,     9,    46,    58,    78,   -95,    89,   154,
     132,   156,    19,    10,   122,    -3,   129,   130,   131,   124,
     163,   164,    20,    -3,    10,    93,    99,   100,   101,   102,
     102,   102,   102,   102,   102,   102,   102,   142,   145,    96,
      54,    98,    55,   125,    22,   117,   112,    62,    63,    56,
     149,   150,   151,   152,   113,    72,    73,    18,    74,   -60,
      25,    26,    27,    28,   161,   162,     9,    29,    30,    31,
      32,    24,    48,    16,    77,    33,     1,    34,    78,    48,
       2,     1,     3,    89,    51,     2,   133,     3,    57,    75,
     143,    68,    69,    92,    88,   -77,   102,   144,   102,     1,
      -3,   140,    97,     2,   111,     3,   114,    59,    60,   121,
     157,   158,   138,    61,    64,    65,    66,    67,   102,     1,
     153,    72,    73,     2,    74,     3,    25,    26,    27,    28,
     103,   104,   115,    29,    30,    31,    32,   118,    48,   109,
     110,    33,   126,    34,    25,    26,    27,    28,   127,   128,
     134,    29,    30,    31,    32,    75,    20,   136,   146,    33,
     147,    34,    25,    26,    27,    28,   148,   159,   160,    29,
      30,    31,    32,   116,   139,   141,    23,    33,   119,    34,
      25,    26,    27,    28,   155,    17,   123,    29,    30,    31,
      32,    75,   137,    49,   135,    33,     0,    34,     0,   105,
     106,   107,   108
};

static const yytype_int16 yycheck[] =
{
      29,    44,    48,    10,    20,    38,    48,    22,    50,   150,
     114,   152,    39,    20,    10,    28,   111,   112,   113,    16,
     161,   162,    37,    36,    20,    54,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   132,   142,    55,
      15,    57,    17,    40,    17,    74,    28,    18,    19,    24,
     145,   146,   147,   148,    36,     5,     6,    15,     8,    17,
      10,    11,    12,    13,   159,   160,    10,    17,    18,    19,
      20,    11,    22,     0,   120,    25,     3,    27,   120,    22,
       7,     3,     9,   125,    14,     7,   115,     9,    37,    39,
     133,    33,    34,    16,    16,    23,   129,   140,   131,     3,
      35,   130,    10,     7,    35,     9,    17,    20,    21,    23,
     153,   154,   128,    26,    29,    30,    31,    32,   151,     3,
     149,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      62,    63,    17,    17,    18,    19,    20,    39,    22,    68,
      69,    25,    14,    27,    10,    11,    12,    13,    16,    40,
      39,    17,    18,    19,    20,    39,    37,    10,    16,    25,
      38,    27,    10,    11,    12,    13,    16,    16,     4,    17,
      18,    19,    20,    39,   129,   131,    15,    25,    78,    27,
      10,    11,    12,    13,   151,     6,    89,    17,    18,    19,
      20,    39,   125,    21,   120,    25,    -1,    27,    -1,    64,
      65,    66,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,     9,    60,    62,    79,    80,    81,    10,
      20,    61,    63,    64,    65,    66,     0,    80,    15,    39,
      37,    83,    17,    64,    11,    10,    11,    12,    13,    17,
      18,    19,    20,    25,    27,    45,    46,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    69,    22,    71,
      82,    14,    58,    59,    15,    17,    24,    37,    49,    20,
      21,    26,    18,    19,    29,    30,    31,    32,    33,    34,
      44,    44,     5,     6,     8,    39,    59,    60,    62,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    16,    62,
      67,    68,    16,    59,    47,    48,    58,    10,    58,    49,
      49,    49,    49,    51,    51,    52,    52,    52,    52,    53,
      53,    35,    28,    36,    17,    17,    39,    59,    39,    63,
      43,    23,    10,    66,    16,    40,    14,    16,    40,    43,
      43,    43,    75,    59,    39,    74,    10,    68,    58,    54,
      59,    55,    43,    44,    44,    75,    16,    38,    16,    43,
      43,    43,    43,    59,    70,    57,    70,    44,    44,    16,
       4,    43,    43,    70,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    45,    45,    45,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    53,    53,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    60,    61,
      61,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      65,    66,    67,    67,    68,    68,    68,    68,    69,    70,
      70,    70,    70,    70,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    82,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     3,     1,
       4,     4,     3,     1,     0,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       5,     1,     5,     1,     9,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     1,     1,     4,     5,     4,
       1,     1,     1,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     0,     1,
       1,     2,     1,     8,    11,     8,    11,     3,     2,     1,
       2,     1,     1,     4,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* M: %empty  */
#line 119 "A5_36.y"
    {
        (yyval.intval) = quad_table->quadArray.size();
    }
#line 1284 "A5_36.tab.c"
    break;

  case 3: /* N: %empty  */
#line 124 "A5_36.y"
    {
        (yyval.smt) = new Statement();
        (yyval.smt)->nextlist = makelist(quad_table->quadArray.size());
        quadTableEntry* tmp = new quadTableEntry("", "", "", GOTO, 0, 0, 0);
        quad_table->emit(tmp);
    }
#line 1295 "A5_36.tab.c"
    break;

  case 4: /* primary_expression: IDENTIFIER  */
#line 133 "A5_36.y"
    {
        SymbolTableEntry * q = cur_symbol_table->lookup((yyvsp[0].ida).var, 0);
        if(!q){
            q = global_symbol_table->lookup((yyvsp[0].ida).var, 0);
        }
        if(!q){
            // yyerror("Error: "+$1.var+" not declared");
            cout<<"Error: "<<(yyvsp[0].ida).var<<" not declared"<<endl;
            exit(1);
        // q = cur_symbol_table->lookup($1.var);

        }
        (yyvsp[0].ida).loc = q;
        (yyval.exp) = new Expression();
        // $$->type = $1.loc->type;
        (yyval.exp)->loc = (yyvsp[0].ida).loc;
    }
#line 1317 "A5_36.tab.c"
    break;

  case 5: /* primary_expression: INTEGER_CONST  */
#line 151 "A5_36.y"
    {
        (yyval.exp) = new Expression();
        SymbolTableEntry * tmp = cur_symbol_table->gentemp(INT4);
        int* g = new int((yyvsp[0].intval));
        tmp->initial_value = g;
        (yyval.exp)->loc = tmp;

        // quadTableEntry* q = new quadTableEntry(to_string($1),"",tmp->name,ASSIGN,nullptr, nullptr, tmp);
        // quad_table->emit(q);
    }
#line 1332 "A5_36.tab.c"
    break;

  case 6: /* primary_expression: CHARACTER_CONST  */
#line 162 "A5_36.y"
    {
        (yyval.exp) = new Expression();
        SymbolTableEntry * tmp = cur_symbol_table->gentemp(CHAR1);
        char* g = new char((yyvsp[0].char_value));
        tmp->initial_value = g;    
        (yyval.exp)->loc = tmp;

        // quadTableEntry* q = new quadTableEntry(to_string($1),"",tmp->name,ASSIGN,nullptr, nullptr, tmp);
        // quad_table->emit(q);    
    }
#line 1347 "A5_36.tab.c"
    break;

  case 7: /* primary_expression: STRING_LITERAL  */
#line 173 "A5_36.y"
    {
        cout<< (yyvsp[0].str_value)<<endl;
        
        (yyval.exp) = new Expression();
        SymbolTableEntry * tmp = cur_symbol_table->gentemp(PTR);
        
        // // cout<< $1<<endl;
        // // string *g = new string($1 );
        // char **g = new char*($1);
        // // const char * g1 = (*g).c_str();
        // // cout<<g1;
        // // char *g2 = g1;
        // // char** arg1 = new char*($1);
        // // // sprintf(arg1,"%s",$1);
        // tmp->initial_value = g;    
        // cout<<*((char **)tmp->initial_value)<<endl;
        tmp->type->next = new typeNode(CHAR1);
        tmp->initial_value = (yyvsp[0].str_value);
        (yyval.exp)->loc = tmp;
        // // char* g = new char($1);
        // // tmp->initial_value = g;
    }
#line 1374 "A5_36.tab.c"
    break;

  case 8: /* primary_expression: RDBLT expression RDBRT  */
#line 196 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[-1].exp);
    }
#line 1382 "A5_36.tab.c"
    break;

  case 9: /* postfix_expression: primary_expression  */
#line 203 "A5_36.y"
    {
        // cout<< $1->loc->name<<" "<<endl;
        (yyval.arr) = new Array();
        (yyval.arr)->array = (yyvsp[0].exp)->loc;
        (yyval.arr)->loc = (yyvsp[0].exp)->loc;
        if((yyvsp[0].exp)->loc)
            (yyval.arr)->type = (yyvsp[0].exp)->loc->type;
    }
#line 1395 "A5_36.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression SQBLT expression SQBRT  */
#line 212 "A5_36.y"
    {
        (yyval.arr) = new Array();

        (yyval.arr)->array = (yyvsp[-3].arr)->array;
        (yyval.arr)->loc = cur_symbol_table->gentemp(INT4);
        (yyval.arr)->atype = "arr";
        (yyval.arr)->type = (yyvsp[-3].arr)->type->next;
        int p = compute_type_size((yyval.arr)->type);

        if((yyvsp[-3].arr)->atype == "arr"){
            SymbolTableEntry *t = cur_symbol_table->gentemp(INT4);
            quadTableEntry* q = new quadTableEntry((yyvsp[-1].exp)->loc->name,to_string(p),t->name,INTO, (yyvsp[-1].exp)->loc, nullptr,t);
            quad_table->emit(q);  

            q = new quadTableEntry((yyvsp[-3].arr)->loc->name,t->name,(yyval.arr)->loc->name,PLUS, (yyvsp[-3].arr)->loc, t,(yyval.arr)->loc);
            quad_table->emit(q);             
        }else{
            quadTableEntry* q = new quadTableEntry((yyvsp[-1].exp)->loc->name,to_string(p),(yyval.arr)->loc->name,INTO,(yyvsp[-1].exp)->loc,nullptr, (yyval.arr)->loc);
            quad_table->emit(q);            
        }
    }
#line 1421 "A5_36.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression RDBLT argument_expression_list_opt RDBRT  */
#line 234 "A5_36.y"
    {
        (yyval.arr) = new Array();
        
        (yyval.arr)->array = cur_symbol_table->gentemp((yyvsp[-3].arr)->loc->type->next->type);
        quadTableEntry * q = new quadTableEntry((yyvsp[-3].arr)->array->name,to_string((yyvsp[-1].num_para)),(yyval.arr)->array->name,CALL,(yyvsp[-3].arr)->array,nullptr,(yyval.arr)->array);
        quad_table->emit(q);
    }
#line 1433 "A5_36.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression PTRARW IDENTIFIER  */
#line 242 "A5_36.y"
    {

    }
#line 1441 "A5_36.tab.c"
    break;

  case 13: /* argument_expression_list_opt: argument_expression_list  */
#line 249 "A5_36.y"
    {
        (yyval.num_para) = (yyvsp[0].num_para);
    }
#line 1449 "A5_36.tab.c"
    break;

  case 14: /* argument_expression_list_opt: %empty  */
#line 253 "A5_36.y"
    {
        (yyval.num_para) = 0;
    }
#line 1457 "A5_36.tab.c"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 260 "A5_36.y"
    {
        (yyval.num_para) = 1;
        quadTableEntry * q = new quadTableEntry((yyvsp[0].exp)->loc->name,"","",PARAM,(yyvsp[0].exp)->loc,nullptr,nullptr);
        quad_table->emit(q);
    }
#line 1467 "A5_36.tab.c"
    break;

  case 16: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 266 "A5_36.y"
    {
        (yyval.num_para) = (yyvsp[-2].num_para) + 1;
        quadTableEntry * q = new quadTableEntry((yyvsp[0].exp)->loc->name,"","",PARAM,(yyvsp[0].exp)->loc,nullptr,nullptr);
        quad_table->emit(q);
    }
#line 1477 "A5_36.tab.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 275 "A5_36.y"
    {
        (yyval.arr) = (yyvsp[0].arr);
    }
#line 1485 "A5_36.tab.c"
    break;

  case 18: /* unary_expression: unary_operator unary_expression  */
#line 279 "A5_36.y"
    {
        (yyval.arr) = new Array();

        switch((yyvsp[-1].uop))
        {
            case U_ADDR:
            {
                (yyval.arr)->array = cur_symbol_table->gentemp(PTR);
                (yyval.arr)->array->type->next = (yyvsp[0].arr)->array->type;
                quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,"",(yyval.arr)->array->name,U_ADDR,(yyvsp[0].arr)->array,nullptr,(yyval.arr)->array);
                quad_table->emit(q);
                break;
            }
            case U_STAR:
            {
                (yyval.arr)->atype = "ptr";
                (yyval.arr)->loc = cur_symbol_table->gentemp((yyvsp[0].arr)->array->type->next->type);
                (yyval.arr)->array = (yyvsp[0].arr)->array;
                quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,"",(yyval.arr)->loc->name,U_STAR,(yyvsp[0].arr)->array,nullptr,(yyval.arr)->loc);
                quad_table->emit(q);
                break;
            }
            case U_PLUS:
            {
                (yyval.arr) = (yyvsp[0].arr);
                break;
            }
            case U_MINUS:
            {
                (yyval.arr)->array = cur_symbol_table->gentemp((yyvsp[0].arr)->array->type->type);
                quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,"",(yyval.arr)->array->name,U_MINUS,(yyvsp[0].arr)->array,nullptr,(yyval.arr)->array);
                quad_table->emit(q);
                break;
            }
            case LNOT:
            {
                (yyval.arr)->array = cur_symbol_table->gentemp((yyvsp[0].arr)->array->type->type);
                quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,"",(yyval.arr)->array->name,LNOT,(yyvsp[0].arr)->array,nullptr,(yyval.arr)->array);
                quad_table->emit(q);
                break;                
            }
        }
    }
#line 1533 "A5_36.tab.c"
    break;

  case 19: /* unary_operator: AMPERSOND  */
#line 326 "A5_36.y"
    {
        (yyval.uop) = U_ADDR;
    }
#line 1541 "A5_36.tab.c"
    break;

  case 20: /* unary_operator: MULT  */
#line 330 "A5_36.y"
    {
        (yyval.uop) = U_STAR;
    }
#line 1549 "A5_36.tab.c"
    break;

  case 21: /* unary_operator: ADD  */
#line 334 "A5_36.y"
    {
        (yyval.uop) = U_PLUS;
    }
#line 1557 "A5_36.tab.c"
    break;

  case 22: /* unary_operator: SUB  */
#line 338 "A5_36.y"
    {
        (yyval.uop) = U_MINUS;
    }
#line 1565 "A5_36.tab.c"
    break;

  case 23: /* unary_operator: NOT  */
#line 342 "A5_36.y"
    {
        (yyval.uop) = LNOT;
    }
#line 1573 "A5_36.tab.c"
    break;

  case 24: /* multiplicative_expression: unary_expression  */
#line 349 "A5_36.y"
    {
        (yyval.exp) = new Expression();

        if((yyvsp[0].arr)->atype == "arr"){
            (yyval.exp)->loc = cur_symbol_table->gentemp((yyvsp[0].arr)->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,(yyvsp[0].arr)->loc->name,(yyval.exp)->loc->name,EQ_BRT,(yyvsp[0].arr)->array,(yyvsp[0].arr)->loc,(yyval.exp)->loc);
            quad_table->emit(q);
        }
        else if((yyvsp[0].arr)->atype == "ptr"){
            (yyval.exp)->loc = (yyvsp[0].arr)->loc;
        }
        else{
            (yyval.exp)->loc = (yyvsp[0].arr)->array;
        }
    }
#line 1593 "A5_36.tab.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression MULT unary_expression  */
#line 365 "A5_36.y"
    {
        Expression* tmp = new Expression();
        if((yyvsp[0].arr)->atype == "arr"){
            tmp->loc = cur_symbol_table->gentemp((yyvsp[0].arr)->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,(yyvsp[0].arr)->loc->name,tmp->loc->name,EQ_BRT,(yyvsp[0].arr)->array,(yyvsp[0].arr)->loc,tmp->loc);
            quad_table->emit(q);
        }
        else if((yyvsp[0].arr)->atype == "ptr"){
            tmp->loc = (yyvsp[0].arr)->loc;
        }
        else{
            tmp->loc = (yyvsp[0].arr)->array;
        }

        if(!typecheck(&((yyvsp[-2].exp)->loc), tmp->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();

            (yyval.exp)->loc = cur_symbol_table->gentemp((yyvsp[-2].exp)->loc->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[-2].exp)->loc->name,tmp->loc->name,(yyval.exp)->loc->name,INTO,(yyvsp[-2].exp)->loc,tmp->loc,(yyval.exp)->loc);
            quad_table->emit(q);

        }
    }
#line 1627 "A5_36.tab.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression DIV unary_expression  */
#line 395 "A5_36.y"
    {
        Expression* tmp = new Expression();
        if((yyvsp[0].arr)->atype == "arr"){
            tmp->loc = cur_symbol_table->gentemp((yyvsp[0].arr)->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,(yyvsp[0].arr)->loc->name,tmp->loc->name,EQ_BRT,(yyvsp[0].arr)->array,(yyvsp[0].arr)->loc,tmp->loc);
            quad_table->emit(q);
        }
        else if((yyvsp[0].arr)->atype == "ptr"){
            tmp->loc = (yyvsp[0].arr)->loc;
        }
        else{
            tmp->loc = (yyvsp[0].arr)->array;
        }

        if(!typecheck(&((yyvsp[-2].exp)->loc), tmp->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->loc = cur_symbol_table->gentemp((yyvsp[-2].exp)->loc->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[-2].exp)->loc->name,tmp->loc->name,(yyval.exp)->loc->name,DIVISION,(yyvsp[-2].exp)->loc,tmp->loc,(yyval.exp)->loc);
            quad_table->emit(q);

        }
    }
#line 1660 "A5_36.tab.c"
    break;

  case 27: /* multiplicative_expression: multiplicative_expression MOD unary_expression  */
#line 424 "A5_36.y"
    {
        Expression* tmp = new Expression();
        if((yyvsp[0].arr)->atype == "arr"){
            tmp->loc = cur_symbol_table->gentemp((yyvsp[0].arr)->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[0].arr)->array->name,(yyvsp[0].arr)->loc->name,tmp->loc->name,EQ_BRT,(yyvsp[0].arr)->array,(yyvsp[0].arr)->loc,tmp->loc);
            quad_table->emit(q);
        }
        else if((yyvsp[0].arr)->atype == "ptr"){
            tmp->loc = (yyvsp[0].arr)->loc;
        }
        else{
            tmp->loc = (yyvsp[0].arr)->array;
        }

        if(!typecheck(&((yyvsp[-2].exp)->loc), tmp->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->loc = cur_symbol_table->gentemp((yyvsp[-2].exp)->loc->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[-2].exp)->loc->name,tmp->loc->name,(yyval.exp)->loc->name,PERCENT,(yyvsp[-2].exp)->loc,tmp->loc,(yyval.exp)->loc);
            quad_table->emit(q);

        }
    }
#line 1693 "A5_36.tab.c"
    break;

  case 28: /* additive_expression: multiplicative_expression  */
#line 456 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1701 "A5_36.tab.c"
    break;

  case 29: /* additive_expression: additive_expression ADD multiplicative_expression  */
#line 460 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->loc = cur_symbol_table->gentemp((yyvsp[-2].exp)->loc->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,(yyval.exp)->loc->name,PLUS,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,(yyval.exp)->loc);
            quad_table->emit(q);

        }
    }
#line 1721 "A5_36.tab.c"
    break;

  case 30: /* additive_expression: additive_expression SUB multiplicative_expression  */
#line 476 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->loc = cur_symbol_table->gentemp((yyvsp[-2].exp)->loc->type->type);
            quadTableEntry *q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,(yyval.exp)->loc->name,MINUS,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,(yyval.exp)->loc);
            quad_table->emit(q);

        }
    }
#line 1741 "A5_36.tab.c"
    break;

  case 31: /* relational_expression: additive_expression  */
#line 495 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1749 "A5_36.tab.c"
    break;

  case 32: /* relational_expression: relational_expression LT additive_expression  */
#line 499 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->truelist = makelist(quad_table->quadArray.size());
            (yyval.exp)->falselist = makelist(quad_table->quadArray.size() + 1);
            (yyval.exp)->type = "bool";
            quadTableEntry* q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,"",GOTOLT,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            
        }        
    }
#line 1772 "A5_36.tab.c"
    break;

  case 33: /* relational_expression: relational_expression GT additive_expression  */
#line 518 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->truelist = makelist(quad_table->quadArray.size());
            (yyval.exp)->falselist = makelist(quad_table->quadArray.size() + 1);
            (yyval.exp)->type = "bool";
            quadTableEntry* q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,"",GOTOGT,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            

        }     
    }
#line 1796 "A5_36.tab.c"
    break;

  case 34: /* relational_expression: relational_expression LTE additive_expression  */
#line 538 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->truelist = makelist(quad_table->quadArray.size());
            (yyval.exp)->falselist = makelist(quad_table->quadArray.size() + 1);
            (yyval.exp)->type = "bool";
            quadTableEntry* q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,"",GOTOLTE,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            

        }     
    }
#line 1820 "A5_36.tab.c"
    break;

  case 35: /* relational_expression: relational_expression GTE additive_expression  */
#line 558 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            (yyval.exp) = new Expression();
            (yyval.exp)->truelist = makelist(quad_table->quadArray.size());
            (yyval.exp)->falselist = makelist(quad_table->quadArray.size() + 1);
            (yyval.exp)->type = "bool";
            quadTableEntry* q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,"",GOTOGTE,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            

        }     
    }
#line 1844 "A5_36.tab.c"
    break;

  case 36: /* equality_expression: relational_expression  */
#line 581 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1852 "A5_36.tab.c"
    break;

  case 37: /* equality_expression: equality_expression EQUALTO relational_expression  */
#line 585 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            convBool2Int((yyvsp[-2].exp));
            convBool2Int((yyvsp[0].exp));

            (yyval.exp) = new Expression();
            (yyval.exp)->type = "bool";
            (yyval.exp)->truelist = makelist(quad_table->quadArray.size());
            (yyval.exp)->falselist = makelist(quad_table->quadArray.size() + 1);            
            quadTableEntry* q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,"",GOTOEQL,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);  
        }     
    }
#line 1878 "A5_36.tab.c"
    break;

  case 38: /* equality_expression: equality_expression NOTEQUAL relational_expression  */
#line 607 "A5_36.y"
    {
        if(!typecheck(&((yyvsp[-2].exp)->loc), (yyvsp[0].exp)->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            convBool2Int((yyvsp[-2].exp));
            convBool2Int((yyvsp[0].exp));

            (yyval.exp) = new Expression();
            (yyval.exp)->type = "bool";
            (yyval.exp)->truelist = makelist(quad_table->quadArray.size());
            (yyval.exp)->falselist = makelist(quad_table->quadArray.size() + 1);            
            quadTableEntry* q = new quadTableEntry((yyvsp[-2].exp)->loc->name,(yyvsp[0].exp)->loc->name,"",GOTONEQL,(yyvsp[-2].exp)->loc,(yyvsp[0].exp)->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);  
        }    
    }
#line 1904 "A5_36.tab.c"
    break;

  case 39: /* logical_AND_expression: equality_expression  */
#line 632 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1912 "A5_36.tab.c"
    break;

  case 40: /* logical_AND_expression: logical_AND_expression N AND M equality_expression  */
#line 636 "A5_36.y"
    {
        convBool2Int((yyvsp[0].exp));
        backpatch((yyvsp[-3].smt)->nextlist, quad_table->quadArray.size());
        convBool2Int((yyvsp[-4].exp));

        (yyval.exp) = new Expression();
        (yyval.exp)->type = "bool";
        backpatch((yyvsp[-4].exp)->truelist,(yyvsp[-1].intval));
        (yyval.exp)->truelist = (yyvsp[0].exp)->truelist;
        (yyval.exp)->falselist = merge((yyvsp[-4].exp)->falselist,(yyvsp[0].exp)->falselist);
    }
#line 1928 "A5_36.tab.c"
    break;

  case 41: /* logical_OR_expression: logical_AND_expression  */
#line 651 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1936 "A5_36.tab.c"
    break;

  case 42: /* logical_OR_expression: logical_OR_expression N OR M logical_AND_expression  */
#line 655 "A5_36.y"
    {
        convBool2Int((yyvsp[0].exp));
        backpatch((yyvsp[-3].smt)->nextlist, quad_table->quadArray.size());
        convBool2Int((yyvsp[-4].exp));

        (yyval.exp) = new Expression();
        (yyval.exp)->type = "bool";
        backpatch((yyvsp[-4].exp)->falselist,(yyvsp[-1].intval));
        (yyval.exp)->truelist = merge((yyvsp[-4].exp)->truelist,(yyvsp[0].exp)->truelist);
        (yyval.exp)->falselist = (yyvsp[0].exp)->falselist;
    }
#line 1952 "A5_36.tab.c"
    break;

  case 43: /* conditional_expression: logical_OR_expression  */
#line 670 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1960 "A5_36.tab.c"
    break;

  case 44: /* conditional_expression: logical_OR_expression N QSTMK M expression N COLN M conditional_expression  */
#line 674 "A5_36.y"
    {
        (yyval.exp)->loc = cur_symbol_table->gentemp((yyvsp[-4].exp)->loc->type->type);
        quadTableEntry* q = new quadTableEntry((yyvsp[0].exp)->loc->name,"",(yyval.exp)->loc->name,ASSIGN,(yyvsp[0].exp)->loc,0,(yyval.exp)->loc);
        quad_table->emit(q);

        list<int> l = makelist(quad_table->quadArray.size());
        q = new quadTableEntry("","","",GOTO,0,0,0);
        quad_table->emit(q); 

        backpatch((yyvsp[-3].smt)->nextlist,quad_table->quadArray.size());
        q = new quadTableEntry((yyvsp[-4].exp)->loc->name,"",(yyval.exp)->loc->name,ASSIGN,(yyvsp[-4].exp)->loc,0,(yyval.exp)->loc);
        quad_table->emit(q);       

        list<int> m = makelist(quad_table->quadArray.size());  
        l = merge(l,m);
        q = new quadTableEntry("","","",GOTO,0,0,0);
        quad_table->emit(q); 

        backpatch((yyvsp[-7].smt)->nextlist,quad_table->quadArray.size());
        conv2Bool((yyvsp[-8].exp));

        backpatch((yyvsp[-8].exp)->truelist, (yyvsp[-5].intval)); 
        backpatch((yyvsp[-8].exp)->falselist, (yyvsp[-1].intval));
        backpatch(l,quad_table->quadArray.size());

    }
#line 1991 "A5_36.tab.c"
    break;

  case 45: /* assignment_expression: conditional_expression  */
#line 704 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1999 "A5_36.tab.c"
    break;

  case 46: /* assignment_expression: unary_expression ASGN assignment_expression  */
#line 708 "A5_36.y"
    {
        if((yyvsp[-2].arr)->atype == "arr"){
            if(!compareTypes((yyvsp[0].exp)->loc->type, (yyvsp[-2].arr)->type))
                (yyvsp[0].exp)->loc = convertTypes((yyvsp[0].exp)->loc,(yyvsp[-2].arr)->type->type);

            quadTableEntry* q = new quadTableEntry((yyvsp[-2].arr)->loc->name,(yyvsp[0].exp)->loc->name,(yyvsp[-2].arr)->array->name,BRT_EQ,(yyvsp[-2].arr)->loc,(yyvsp[0].exp)->loc,(yyvsp[-2].arr)->array);
            quad_table->emit(q);  

        }else if((yyvsp[-2].arr)->atype == "ptr"){
            typecheck(&((yyvsp[0].exp)->loc),(yyvsp[-2].arr)->loc);
            quadTableEntry* q = new quadTableEntry((yyvsp[0].exp)->loc->name,"",(yyvsp[-2].arr)->array->name,STAR_ASSIGN,(yyvsp[0].exp)->loc,nullptr,(yyvsp[-2].arr)->array);
            quad_table->emit(q);            
        }else{
            typecheck(&((yyvsp[0].exp)->loc),(yyvsp[-2].arr)->array);
            quadTableEntry* q = new quadTableEntry((yyvsp[0].exp)->loc->name,"",(yyvsp[-2].arr)->array->name,ASSIGN,(yyvsp[0].exp)->loc,nullptr,(yyvsp[-2].arr)->array);
            quad_table->emit(q);
        }

        (yyval.exp) = (yyvsp[0].exp);
    }
#line 2024 "A5_36.tab.c"
    break;

  case 47: /* expression: assignment_expression  */
#line 732 "A5_36.y"
    {
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 2032 "A5_36.tab.c"
    break;

  case 48: /* declaration: type_specifier init_declarator SCOLN  */
#line 738 "A5_36.y"
                                        {}
#line 2038 "A5_36.tab.c"
    break;

  case 49: /* init_declarator: declarator  */
#line 743 "A5_36.y"
    {
        (yyval.ste) = (yyvsp[0].ste);
    }
#line 2046 "A5_36.tab.c"
    break;

  case 50: /* init_declarator: declarator ASGN initializer  */
#line 747 "A5_36.y"
    {
        typecheck(&((yyvsp[0].ste)),(yyvsp[-2].ste));
        quadTableEntry *q = new quadTableEntry((yyvsp[0].ste)->name,"",(yyvsp[-2].ste)->name,ASSIGN,(yyvsp[0].ste),nullptr,(yyvsp[-2].ste));
        quad_table->emit(q);
    }
#line 2056 "A5_36.tab.c"
    break;

  case 51: /* type_specifier: VOID  */
#line 755 "A5_36.y"
        {
        cur_type = VOID0;
    }
#line 2064 "A5_36.tab.c"
    break;

  case 52: /* type_specifier: CHAR  */
#line 758 "A5_36.y"
         {
        cur_type = CHAR1;
    }
#line 2072 "A5_36.tab.c"
    break;

  case 53: /* type_specifier: INT  */
#line 761 "A5_36.y"
        {
        cur_type = INT4;
    }
#line 2080 "A5_36.tab.c"
    break;

  case 54: /* declarator: pointer direct_declarator  */
#line 768 "A5_36.y"
    {
        typeNode* t = new typeNode(PTR);
        t->next = (yyvsp[0].ste)->type;
        (yyvsp[0].ste)->update(t,(yyvsp[0].ste)->initial_value,(yyvsp[0].ste)->nested_table);
        (yyval.ste) = (yyvsp[0].ste);
    }
#line 2091 "A5_36.tab.c"
    break;

  case 55: /* declarator: direct_declarator  */
#line 775 "A5_36.y"
    {
    }
#line 2098 "A5_36.tab.c"
    break;

  case 56: /* direct_declarator: IDENTIFIER  */
#line 781 "A5_36.y"
    {
        (yyvsp[0].ida).loc = cur_symbol_table->lookup(((yyvsp[0].ida).var));
        (yyvsp[0].ida).loc->update(new typeNode(cur_type), (yyvsp[0].ida).loc->initial_value, (yyvsp[0].ida).loc->nested_table);
        (yyval.ste) = (yyvsp[0].ida).loc;
        cur_symbol_entry = (yyval.ste);
    }
#line 2109 "A5_36.tab.c"
    break;

  case 57: /* direct_declarator: IDENTIFIER SQBLT INTEGER_CONST SQBRT  */
#line 787 "A5_36.y"
                                         {
        (yyvsp[-3].ida).loc = cur_symbol_table->lookup(((yyvsp[-3].ida).var));
        (yyvsp[-3].ida).loc->update(new typeNode(cur_type), (yyvsp[-3].ida).loc->initial_value, (yyvsp[-3].ida).loc->nested_table);

        typeNode *t = new typeNode(ARRAY,(yyvsp[-3].ida).loc->type,(yyvsp[-1].intval));
        (yyvsp[-3].ida).loc->update(t,(yyvsp[-3].ida).loc->initial_value, (yyvsp[-3].ida).loc->nested_table);
        (yyval.ste) = (yyvsp[-3].ida).loc;

        cur_symbol_entry = (yyval.ste);
    }
#line 2124 "A5_36.tab.c"
    break;

  case 58: /* direct_declarator: PRA RDBLT changetable_dec parameter_list RDBRT  */
#line 798 "A5_36.y"
    {
        (yyvsp[-4].ida).loc = global_symbol_table->lookup(((yyvsp[-4].ida).var));
        // $1.loc->update(new typeNode(cur_type), $1.loc->initial_value, $1.loc->nested_table);

        SymbolTableEntry* ret =  cur_symbol_table->lookup("retVal");
        ret->update(new typeNode((yyvsp[-4].ida).loc->type->type),ret->initial_value, ret->nested_table);
    
        cur_symbol_table->parent = global_symbol_table;
        (yyvsp[-4].ida).loc->update(new typeNode(FUNCTION),(yyvsp[-4].ida).loc->initial_value,cur_symbol_table);
        (yyvsp[-4].ida).loc->type->next = copyType(ret->type);
        (yyvsp[-4].ida).loc->type->parameters = (yyvsp[-1].tpn);
        cur_symbol_table = global_symbol_table;

        (yyval.ste) = (yyvsp[-4].ida).loc;
        cur_symbol_entry = (yyval.ste);

    }
#line 2146 "A5_36.tab.c"
    break;

  case 59: /* direct_declarator: PRA RDBLT changetable_dec RDBRT  */
#line 816 "A5_36.y"
    {
        (yyvsp[-3].ida).loc = global_symbol_table->lookup(((yyvsp[-3].ida).var));
        // $1.loc->update(new typeNode(cur_type), $1.loc->initial_value, $1.loc->nested_table);
        
        SymbolTableEntry* ret =  cur_symbol_table->lookup("retVal");
        ret->update(new typeNode((yyvsp[-3].ida).loc->type->type),ret->initial_value, ret->nested_table);


        cur_symbol_table->parent = global_symbol_table;
        (yyvsp[-3].ida).loc->update(new typeNode(FUNCTION),(yyvsp[-3].ida).loc->initial_value,cur_symbol_table);
        (yyvsp[-3].ida).loc->type->next = copyType(ret->type);
        // $1.loc->type->parameters = $4;
        cur_symbol_table = global_symbol_table;


        cur_symbol_entry = (yyval.ste);
    }
#line 2168 "A5_36.tab.c"
    break;

  case 60: /* PRA: IDENTIFIER  */
#line 835 "A5_36.y"
               {
    (yyvsp[0].ida).loc = global_symbol_table->lookup(((yyvsp[0].ida).var));
    (yyvsp[0].ida).loc->update(new typeNode(cur_type), (yyvsp[0].ida).loc->initial_value, (yyvsp[0].ida).loc->nested_table);

    cur_symbol_entry = (yyvsp[0].ida).loc;
    (yyval.ida) = (yyvsp[0].ida);
}
#line 2180 "A5_36.tab.c"
    break;

  case 62: /* parameter_list: parameter_declaration  */
#line 848 "A5_36.y"
                          {
        (yyval.tpn) = (yyvsp[0].tpn);
    }
#line 2188 "A5_36.tab.c"
    break;

  case 63: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 852 "A5_36.y"
    {
        typeNode *tm = (yyvsp[-2].tpn);
        while(tm->next){
            tm = tm->next;
        }
        tm->next = (yyvsp[0].tpn);
        (yyval.tpn) = (yyvsp[-2].tpn);
    }
#line 2201 "A5_36.tab.c"
    break;

  case 64: /* parameter_declaration: type_specifier pointer IDENTIFIER  */
#line 864 "A5_36.y"
    {
        (yyvsp[0].ida).loc = cur_symbol_table->lookup(((yyvsp[0].ida).var));
        (yyvsp[0].ida).loc->update(new typeNode(cur_type), (yyvsp[0].ida).loc->initial_value, (yyvsp[0].ida).loc->nested_table);     

        typeNode* t = new typeNode(PTR);
        t->next = (yyvsp[0].ida).loc->type;

        (yyval.tpn) = new typeNode(PTR);
        (yyval.tpn)->next = new typeNode(cur_type);
        (yyval.tpn)->next->next = new typeNode(DEFLT);
        (yyvsp[0].ida).loc->update(t,(yyvsp[0].ida).loc->initial_value,(yyvsp[0].ida).loc->nested_table);
    }
#line 2218 "A5_36.tab.c"
    break;

  case 65: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 877 "A5_36.y"
    {
        (yyval.tpn) = new typeNode(cur_type);
        (yyval.tpn)->next = new typeNode(DEFLT);
        (yyvsp[0].ida).loc = cur_symbol_table->lookup(((yyvsp[0].ida).var));

        (yyvsp[0].ida).loc->update(new typeNode(cur_type), (yyvsp[0].ida).loc->initial_value, (yyvsp[0].ida).loc->nested_table);
    }
#line 2230 "A5_36.tab.c"
    break;

  case 66: /* parameter_declaration: type_specifier pointer  */
#line 885 "A5_36.y"
    {
        (yyval.tpn) = new typeNode(PTR);
        (yyval.tpn)->next = new typeNode(cur_type);
        (yyval.tpn)->next->next = new typeNode(DEFLT);
    }
#line 2240 "A5_36.tab.c"
    break;

  case 67: /* parameter_declaration: type_specifier  */
#line 891 "A5_36.y"
    {
        (yyval.tpn) = new typeNode(cur_type);
        (yyval.tpn)->next = new typeNode(DEFLT);        
    }
#line 2249 "A5_36.tab.c"
    break;

  case 68: /* initializer: assignment_expression  */
#line 899 "A5_36.y"
    {
        (yyval.ste) = (yyvsp[0].exp)->loc;
    }
#line 2257 "A5_36.tab.c"
    break;

  case 69: /* statement: compound_statement  */
#line 906 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
    }
#line 2265 "A5_36.tab.c"
    break;

  case 70: /* statement: expression_statement  */
#line 910 "A5_36.y"
    {
        (yyval.smt) = new Statement();
        (yyval.smt)->nextlist = (yyvsp[0].exp)->nextlist;
    }
#line 2274 "A5_36.tab.c"
    break;

  case 71: /* statement: selection_statement  */
#line 915 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
    }
#line 2282 "A5_36.tab.c"
    break;

  case 72: /* statement: iteration_statement  */
#line 919 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
    }
#line 2290 "A5_36.tab.c"
    break;

  case 73: /* statement: jump_statement  */
#line 923 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
    }
#line 2298 "A5_36.tab.c"
    break;

  case 74: /* compound_statement: CRBLT block_item_list_opt CRBRT  */
#line 930 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[-1].smt);
    }
#line 2306 "A5_36.tab.c"
    break;

  case 75: /* block_item_list: block_item  */
#line 937 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
    }
#line 2314 "A5_36.tab.c"
    break;

  case 76: /* block_item_list: block_item_list M block_item  */
#line 941 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
        backpatch((yyvsp[-2].smt)->nextlist,(yyvsp[-1].intval));
    }
#line 2323 "A5_36.tab.c"
    break;

  case 77: /* block_item_list_opt: block_item_list  */
#line 949 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
    }
#line 2331 "A5_36.tab.c"
    break;

  case 78: /* block_item_list_opt: %empty  */
#line 953 "A5_36.y"
    {
        (yyval.smt) = new Statement();;
    }
#line 2339 "A5_36.tab.c"
    break;

  case 79: /* block_item: declaration  */
#line 960 "A5_36.y"
    {
        (yyval.smt) = new Statement();
    }
#line 2347 "A5_36.tab.c"
    break;

  case 80: /* block_item: statement  */
#line 964 "A5_36.y"
    {
        (yyval.smt) = (yyvsp[0].smt);
    }
#line 2355 "A5_36.tab.c"
    break;

  case 81: /* expression_statement: expression SCOLN  */
#line 971 "A5_36.y"
    {
        (yyval.exp)=(yyvsp[-1].exp);
    }
#line 2363 "A5_36.tab.c"
    break;

  case 82: /* expression_statement: SCOLN  */
#line 976 "A5_36.y"
    {
        (yyval.exp) = new Expression();
    }
#line 2371 "A5_36.tab.c"
    break;

  case 83: /* selection_statement: IF RDBLT expression N RDBRT M statement N  */
#line 983 "A5_36.y"
    {
        backpatch((yyvsp[-4].smt)->nextlist,quad_table->quadArray.size());
        conv2Bool((yyvsp[-5].exp));

        (yyval.smt) = new Statement();
        backpatch((yyvsp[-5].exp)->truelist, (yyvsp[-2].intval));
        list<int> temp = merge((yyvsp[-5].exp)->falselist, (yyvsp[-1].smt)->nextlist);
        (yyval.smt)->nextlist = merge((yyvsp[0].smt)->nextlist,temp);
    }
#line 2385 "A5_36.tab.c"
    break;

  case 84: /* selection_statement: IF RDBLT expression N RDBRT M statement N ELSE M statement  */
#line 993 "A5_36.y"
    {
        backpatch((yyvsp[-7].smt)->nextlist,quad_table->quadArray.size());
        conv2Bool((yyvsp[-8].exp));

        (yyval.smt) = new Statement();
        backpatch((yyvsp[-8].exp)->truelist, (yyvsp[-5].intval));
        backpatch((yyvsp[-8].exp)->falselist, (yyvsp[-1].intval));
        list<int> temp = merge((yyvsp[-4].smt)->nextlist, (yyvsp[-3].smt)->nextlist);
        (yyval.smt)->nextlist = merge((yyvsp[0].smt)->nextlist,temp);
    }
#line 2400 "A5_36.tab.c"
    break;

  case 85: /* iteration_statement: FOR RDBLT expression_statement M expression_statement RDBRT M statement  */
#line 1007 "A5_36.y"
    {
        (yyval.smt) = new Statement();
        conv2Bool((yyvsp[-3].exp));
        backpatch((yyvsp[-3].exp)->truelist, (yyvsp[-1].intval));
        backpatch((yyvsp[0].smt)->nextlist, (yyvsp[-4].intval));
        quadTableEntry* q = new quadTableEntry("","",to_string((yyvsp[-4].intval)),GOTO,0,0,0);
        quad_table->emit(q);
        (yyval.smt)->nextlist = (yyvsp[-3].exp)->falselist;
    }
#line 2414 "A5_36.tab.c"
    break;

  case 86: /* iteration_statement: FOR RDBLT expression_statement M expression_statement M expression N RDBRT M statement  */
#line 1017 "A5_36.y"
    {
        (yyval.smt) = new Statement();
        conv2Bool((yyvsp[-6].exp));
        backpatch((yyvsp[-6].exp)->truelist, (yyvsp[-1].intval));
        backpatch((yyvsp[-3].smt)->nextlist, (yyvsp[-7].intval));
        backpatch((yyvsp[0].smt)->nextlist, (yyvsp[-5].intval));
        quadTableEntry* q = new quadTableEntry("","",to_string((yyvsp[-5].intval)),GOTO,0,0,0);
        quad_table->emit(q);
        (yyval.smt)->nextlist = (yyvsp[-6].exp)->falselist;
    }
#line 2429 "A5_36.tab.c"
    break;

  case 87: /* jump_statement: RETURN expression SCOLN  */
#line 1031 "A5_36.y"
    {
        (yyval.smt) = new Statement();
        quadTableEntry* q = new quadTableEntry((yyvsp[-1].exp)->loc->name,"","",RETURN_EXPN,(yyvsp[-1].exp)->loc,0,0);
        quad_table->emit(q);
    }
#line 2439 "A5_36.tab.c"
    break;

  case 88: /* jump_statement: RETURN SCOLN  */
#line 1038 "A5_36.y"
    {
        (yyval.smt) = new Statement();
        quadTableEntry* q = new quadTableEntry("","","",RETURN_,0,0,0);
        quad_table->emit(q);
    }
#line 2449 "A5_36.tab.c"
    break;

  case 89: /* translation_unit: external_declaration  */
#line 1046 "A5_36.y"
                         {}
#line 2455 "A5_36.tab.c"
    break;

  case 90: /* translation_unit: translation_unit external_declaration  */
#line 1047 "A5_36.y"
                                           {}
#line 2461 "A5_36.tab.c"
    break;

  case 91: /* external_declaration: function_definition  */
#line 1051 "A5_36.y"
                        {}
#line 2467 "A5_36.tab.c"
    break;

  case 92: /* external_declaration: declaration  */
#line 1052 "A5_36.y"
                     {}
#line 2473 "A5_36.tab.c"
    break;

  case 93: /* function_definition: type_specifier declarator changetable_def compound_statement  */
#line 1057 "A5_36.y"
    {
        cur_symbol_table = global_symbol_table;
    }
#line 2481 "A5_36.tab.c"
    break;

  case 94: /* changetable_dec: %empty  */
#line 1063 "A5_36.y"
    {
        if(cur_symbol_entry->nested_table == nullptr){
            SymbolTable *s = new SymbolTable(cur_symbol_entry->name);
            cur_symbol_table = s;
        }
        else{
            cur_symbol_table = cur_symbol_entry->nested_table;
            // quad_table->emit(new quadTableEntry(cur_symbol_table->STName,"","",FUCN,cur_symbol_entry,nullptr, nullptr));
        }
    }
#line 2496 "A5_36.tab.c"
    break;

  case 95: /* changetable_def: %empty  */
#line 1076 "A5_36.y"
    {
        cur_symbol_table = cur_symbol_entry->nested_table;
        quad_table->emit(new quadTableEntry(cur_symbol_table->STName,"","",FUCN,cur_symbol_entry,nullptr, nullptr));
    }
#line 2505 "A5_36.tab.c"
    break;


#line 2509 "A5_36.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1082 "A5_36.y"


int yyerror(char const *s) {
    // printf("error at %d",yylineno);
    return 0;
}


