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
    LPAREN = 258,                  /* LPAREN  */
    RPAREN = 259,                  /* RPAREN  */
    LCURLY = 260,                  /* LCURLY  */
    RCURLY = 261,                  /* RCURLY  */
    LSQUARE = 262,                 /* LSQUARE  */
    RSQUARE = 263,                 /* RSQUARE  */
    NUMBER = 264,                  /* NUMBER  */
    ACCESS = 265,                  /* ACCESS  */
    POINTER_ACCESS = 266,          /* POINTER_ACCESS  */
    INC = 267,                     /* INC  */
    DEC = 268,                     /* DEC  */
    PLUS = 269,                    /* PLUS  */
    MINUS = 270,                   /* MINUS  */
    NOT = 271,                     /* NOT  */
    LNOT = 272,                    /* LNOT  */
    MUL = 273,                     /* MUL  */
    ADDROF = 274,                  /* ADDROF  */
    DIV = 275,                     /* DIV  */
    REM = 276,                     /* REM  */
    SHL = 277,                     /* SHL  */
    SHR = 278,                     /* SHR  */
    LT = 279,                      /* LT  */
    LE = 280,                      /* LE  */
    GT = 281,                      /* GT  */
    GE = 282,                      /* GE  */
    EQ = 283,                      /* EQ  */
    NE = 284,                      /* NE  */
    AND = 285,                     /* AND  */
    XOR = 286,                     /* XOR  */
    OR = 287,                      /* OR  */
    LAND = 288,                    /* LAND  */
    LOR = 289,                     /* LOR  */
    TERNQ = 290,                   /* TERNQ  */
    COLON = 291,                   /* COLON  */
    ASS = 292,                     /* ASS  */
    CHADD = 293,                   /* CHADD  */
    CHSUB = 294,                   /* CHSUB  */
    CHMUL = 295,                   /* CHMUL  */
    CHDIV = 296,                   /* CHDIV  */
    CHREM = 297,                   /* CHREM  */
    CHSHL = 298,                   /* CHSHL  */
    CHSHR = 299,                   /* CHSHR  */
    CHAND = 300,                   /* CHAND  */
    CHXOR = 301,                   /* CHXOR  */
    CHOR = 302,                    /* CHOR  */
    COMMA = 303,                   /* COMMA  */
    AUTO = 304,                    /* AUTO  */
    DOUBLE = 305,                  /* DOUBLE  */
    INT = 306,                     /* INT  */
    STRUCT = 307,                  /* STRUCT  */
    BREAK = 308,                   /* BREAK  */
    ELSE = 309,                    /* ELSE  */
    LONG = 310,                    /* LONG  */
    SWITCH = 311,                  /* SWITCH  */
    CASE = 312,                    /* CASE  */
    ENUM = 313,                    /* ENUM  */
    REGISTER = 314,                /* REGISTER  */
    TYPEDEF = 315,                 /* TYPEDEF  */
    CHAR = 316,                    /* CHAR  */
    EXTERN = 317,                  /* EXTERN  */
    RETURN = 318,                  /* RETURN  */
    UNION = 319,                   /* UNION  */
    CONST = 320,                   /* CONST  */
    FLOAT = 321,                   /* FLOAT  */
    SHORT = 322,                   /* SHORT  */
    UNSIGNED = 323,                /* UNSIGNED  */
    CONTINUE = 324,                /* CONTINUE  */
    FOR = 325,                     /* FOR  */
    SIGNED = 326,                  /* SIGNED  */
    VOID = 327,                    /* VOID  */
    DEFAULT = 328,                 /* DEFAULT  */
    GOTO = 329,                    /* GOTO  */
    SIZEOF = 330,                  /* SIZEOF  */
    VOLATILE = 331,                /* VOLATILE  */
    DO = 332,                      /* DO  */
    IF = 333,                      /* IF  */
    STATIC = 334,                  /* STATIC  */
    WHILE = 335,                   /* WHILE  */
    _BOOL = 336,                   /* _BOOL  */
    _IMAGINARY = 337,              /* _IMAGINARY  */
    RESTRICT = 338,                /* RESTRICT  */
    _COMPLEX = 339,                /* _COMPLEX  */
    INLINE = 340,                  /* INLINE  */
    IDENTIFIER = 341,              /* IDENTIFIER  */
    SEMICOLON = 342                /* SEMICOLON  */
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
