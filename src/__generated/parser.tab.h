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

#ifndef YY_YY_SRC_GENERATED_PARSER_TAB_H_INCLUDED
# define YY_YY_SRC_GENERATED_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "src/parser.y"

   #include "ast.h"

#line 53 "src/__generated/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    COMMA = 258,                   /* COMMA  */
    TERNQ = 259,                   /* TERNQ  */
    COLON = 260,                   /* COLON  */
    LOR = 261,                     /* LOR  */
    LAND = 262,                    /* LAND  */
    OR = 263,                      /* OR  */
    XOR = 264,                     /* XOR  */
    AND = 265,                     /* AND  */
    EQ = 266,                      /* EQ  */
    NE = 267,                      /* NE  */
    GT = 268,                      /* GT  */
    GE = 269,                      /* GE  */
    LT = 270,                      /* LT  */
    LE = 271,                      /* LE  */
    SHL = 272,                     /* SHL  */
    SHR = 273,                     /* SHR  */
    DIV = 274,                     /* DIV  */
    REM = 275,                     /* REM  */
    LPAREN = 276,                  /* LPAREN  */
    RPAREN = 277,                  /* RPAREN  */
    LCURLY = 278,                  /* LCURLY  */
    RCURLY = 279,                  /* RCURLY  */
    LSQUARE = 280,                 /* LSQUARE  */
    RSQUARE = 281,                 /* RSQUARE  */
    NUMBER = 282,                  /* NUMBER  */
    ACCESS = 283,                  /* ACCESS  */
    POINTER_ACCESS = 284,          /* POINTER_ACCESS  */
    INC = 285,                     /* INC  */
    DEC = 286,                     /* DEC  */
    AUTO = 287,                    /* AUTO  */
    DOUBLE = 288,                  /* DOUBLE  */
    INT = 289,                     /* INT  */
    STRUCT = 290,                  /* STRUCT  */
    BREAK = 291,                   /* BREAK  */
    ELSE = 292,                    /* ELSE  */
    LONG = 293,                    /* LONG  */
    SWITCH = 294,                  /* SWITCH  */
    CASE = 295,                    /* CASE  */
    ENUM = 296,                    /* ENUM  */
    REGISTER = 297,                /* REGISTER  */
    TYPEDEF = 298,                 /* TYPEDEF  */
    CHAR = 299,                    /* CHAR  */
    EXTERN = 300,                  /* EXTERN  */
    RETURN = 301,                  /* RETURN  */
    UNION = 302,                   /* UNION  */
    CONST = 303,                   /* CONST  */
    FLOAT = 304,                   /* FLOAT  */
    SHORT = 305,                   /* SHORT  */
    UNSIGNED = 306,                /* UNSIGNED  */
    CONTINUE = 307,                /* CONTINUE  */
    FOR = 308,                     /* FOR  */
    SIGNED = 309,                  /* SIGNED  */
    VOID = 310,                    /* VOID  */
    DEFAULT = 311,                 /* DEFAULT  */
    GOTO = 312,                    /* GOTO  */
    SIZEOF = 313,                  /* SIZEOF  */
    VOLATILE = 314,                /* VOLATILE  */
    DO = 315,                      /* DO  */
    IF = 316,                      /* IF  */
    STATIC = 317,                  /* STATIC  */
    WHILE = 318,                   /* WHILE  */
    _BOOL = 319,                   /* _BOOL  */
    _IMAGINARY = 320,              /* _IMAGINARY  */
    RESTRICT = 321,                /* RESTRICT  */
    _COMPLEX = 322,                /* _COMPLEX  */
    INLINE = 323,                  /* INLINE  */
    IDENTIFIER = 324,              /* IDENTIFIER  */
    SEMICOLON = 325,               /* SEMICOLON  */
    PLUS = 326,                    /* PLUS  */
    MINUS = 327,                   /* MINUS  */
    NOT = 328,                     /* NOT  */
    LNOT = 329,                    /* LNOT  */
    MUL = 330,                     /* MUL  */
    ADDROF = 331,                  /* ADDROF  */
    ASS = 332,                     /* ASS  */
    CHADD = 333,                   /* CHADD  */
    CHSUB = 334,                   /* CHSUB  */
    CHMUL = 335,                   /* CHMUL  */
    CHDIV = 336,                   /* CHDIV  */
    CHREM = 337,                   /* CHREM  */
    CHSHL = 338,                   /* CHSHL  */
    CHSHR = 339,                   /* CHSHR  */
    CHAND = 340,                   /* CHAND  */
    CHXOR = 341,                   /* CHXOR  */
    CHOR = 342                     /* CHOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  ast_node_t *  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_GENERATED_PARSER_TAB_H_INCLUDED  */
