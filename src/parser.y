%{
#include <stdio.h>
#include <stdlib.h>

int yyerror(char *s);
int yylex(void);
extern void yy_scan_string(const char *);
extern void yy_delete_buffer(int);
%}

%left LPAREN RPAREN NUMBER
%left LOR
%left LAND
%left OR XOR AND
%left EQ NE
%left LT LE GT GE
%left SHL SHR
%left PLUS MINUS
%left MUL DIV REM
%right NOT LNOT 

%%
expr:
    |           LPAREN  expr RPAREN
    |           NOT     expr
    |           LNOT    expr
    |    expr   PLUS    expr
    |    expr   MINUS   expr
    |    expr   MUL     expr
    |    expr   DIV     expr
    |    expr   REM     expr
    |    expr   AND     expr
    |    expr   OR      expr
    |    expr   XOR     expr
    |    expr   SHL     expr
    |    expr   SHR     expr
    |    expr   LAND    expr
    |    expr   LOR     expr
    |    expr   EQ      expr
    |    expr   NE      expr
    |    expr   LT      expr
    |    expr   LE      expr
    |    expr   GT      expr
    |    expr   GE      expr
    |    NUMBER
    ;
%%

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

int parse() {
    char input[] = "2 * (3 + 4) - 5";
    yy_scan_string(input);  // Pass the string to the lexer
    return yyparse();
    yy_delete_buffer(0);
}