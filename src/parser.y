%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

ast_node_t *root;

extern int yylineno;
int yyerror(char *s);
int yylex(void);
extern void yy_scan_string(const char *);
extern void yy_delete_buffer(int);
%}

%code requires {
   #include "ast.h"
}

%define api.value.type { ast_node_t * }
%left COMMA
%right TERNQ COLON 
%left LOR
%left LAND
%left OR
%left XOR
%left AND
%left EQ NE 
%left GT GE 
%left LT LE
%left SHL SHR
%left DIV REM
%left LPAREN RPAREN LCURLY RCURLY LSQUARE RSQUARE NUMBER ACCESS POINTER_ACCESS INC DEC
%right AUTO DOUBLE INT STRUCT BREAK ELSE LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR EXTERN RETURN UNION CONST FLOAT SHORT UNSIGNED CONTINUE FOR SIGNED VOID DEFAULT GOTO SIZEOF VOLATILE DO IF STATIC WHILE _BOOL _IMAGINARY RESTRICT _COMPLEX INLINE 
%left IDENTIFIER SEMICOLON
%right PLUS MINUS NOT LNOT MUL ADDROF
%right ASS CHADD CHSUB CHMUL CHDIV CHREM CHSHL CHSHR CHAND CHXOR CHOR 

//keywords


%%
statement: 
         expr { root = $1; }
    |    IDENTIFIER   ASS     expr       { root = ast_new_binary_node(ASTTYPE_ASSIGNMENT, $1, $3); }
    |    type_decl IDENTIFIER definition { root = ast_new_declaration($2, $1, $3); }
    ;

expr:
    |           LPAREN  expr RPAREN       { printf("()\n");$$ = $2; }
    |           NOT     expr              { printf("~\n");$$ = ast_new_unary_node(ASTTYPE_BINARY_NOT, $2); }
    |           LNOT    expr              { printf("!\n");$$ = ast_new_unary_node(ASTTYPE_LOGICAL_NOT, $2); }
    |           INC     expr              { printf("++\n");$$ = ast_new_unary_node(ASTTYPE_INCREMENT, $2); }
    |           DEC     expr              { printf("--\n");$$ = ast_new_unary_node(ASTTYPE_DECREMENT, $2); }
    |           ADDROF  expr              { printf("&a\n");$$ = ast_new_unary_node(ASTTYPE_ADDRESS_OF, $2); }
    |           MUL     expr              { printf("*a\n");$$ = ast_new_unary_node(ASTTYPE_DEREFERENCE, $2); }
    |    expr   INC                       { printf("++\n");$$ = ast_new_unary_node(ASTTYPE_INCREMENT, $1); }
    |    expr   DEC                       { printf("--\n");$$ = ast_new_unary_node(ASTTYPE_DECREMENT, $1); }
    |    expr   PLUS    expr              { printf("+\n");$$ = ast_new_binary_node(ASTTYPE_ADDITION, $1, $3); } 
    |    expr   MINUS   expr              { printf("-\n");$$ = ast_new_binary_node(ASTTYPE_SUBTRACTION, $1, $3); }
    |    expr   MUL     expr              { printf("*\n");$$ = ast_new_binary_node(ASTTYPE_MULTIPLICATION, $1, $3); }
    |    expr   DIV     expr              { printf("/\n");$$ = ast_new_binary_node(ASTTYPE_DIVISION, $1, $3); }
    |    expr   REM     expr              { printf("%\n");$$ = ast_new_binary_node(ASTTYPE_MODULO, $1, $3); }
    |    expr   AND     expr              { printf("&\n");$$ = ast_new_binary_node(ASTTYPE_LOGICAL_AND, $1, $3); }
    |    expr   OR      expr              { printf("|\n");$$ = ast_new_binary_node(ASTTYPE_LOGICAL_OR, $1, $3); }
    |    expr   XOR     expr              { printf("^\n");$$ = ast_new_binary_node(ASTTYPE_BINARY_XOR, $1, $3); }
    |    expr   SHL     expr              { printf("<<\n");$$ = ast_new_binary_node(ASTTYPE_LEFT_SHIFT, $1, $3); }
    |    expr   SHR     expr              { printf(">>\n");$$ = ast_new_binary_node(ASTTYPE_RIGHT_SHIFT, $1, $3); }
    |    expr   LAND    expr              { printf("&&\n");$$ = ast_new_binary_node(ASTTYPE_LOGICAL_AND, $1, $3); }
    |    expr   LOR     expr              { printf("||\n");$$ = ast_new_binary_node(ASTTYPE_LOGICAL_OR, $1, $3); }
    |    expr   EQ      expr              { printf("==\n");$$ = ast_new_binary_node(ASTTYPE_EQUAL, $1, $3); }
    |    expr   NE      expr              { printf("!=\n");$$ = ast_new_binary_node(ASTTYPE_NOT_EQUAL, $1, $3); }
    |    expr   LT      expr              { printf("<\n");$$ = ast_new_binary_node(ASTTYPE_LESS_THAN, $1, $3); }
    |    expr   LE      expr              { printf("<=\n");$$ = ast_new_binary_node(ASTTYPE_LESS_THAN_EQUAL, $1, $3); }
    |    expr   GT      expr              { printf(">\n");$$ = ast_new_binary_node(ASTTYPE_GREATER_THAN, $1, $3); }
    |    expr   GE      expr              { printf(">=\n");$$ = ast_new_binary_node(ASTTYPE_GREATER_THAN_EQUAL, $1, $3); }
    |    expr   TERNQ   expr COLON expr   { printf("?:\n");$$ = ast_new_trinary_node($1, $3, $5); }
    |    NUMBER                           { printf("num\n");$$ = $1; }
    |    IDENTIFIER                       /* omg I forgot about variable usage */
    ;
definition:
    /* empty */               { $$ = NULL; }
    | ASS expr                { $$ = $2; }
    ;

type_decl:
    | VOID    { $$ = ast_new_vartype("void"); }
    | INT     { $$ = ast_new_vartype("int"); }
    | FLOAT   { $$ = ast_new_vartype("float"); }
    | CHAR    { $$ = ast_new_vartype("char"); }
    | DOUBLE  { $$ = ast_new_vartype("double"); }
    | LONG    { $$ = ast_new_vartype("long"); }
    | SHORT   { $$ = ast_new_vartype("short"); }
    | type_decl MUL { $$ = ast_amend_pointer($1); }
    | qualifier type_decl { $$ = ast_amend_vartype_qualifier($2, $1); }
    ;

qualifier:
      CONST     { $$ = ast_new_qualifier(QUALIFIER_CONST); }
    | VOLATILE  { $$ = ast_new_qualifier(QUALIFIER_VOLATILE); }
    | RESTRICT  { $$ = ast_new_qualifier(QUALIFIER_RESTRICT); }
    | STATIC    { $$ = ast_new_qualifier(QUALIFIER_STATIC); }
    | EXTERN    { $$ = ast_new_qualifier(QUALIFIER_EXTERN); }
    | REGISTER  { $$ = ast_new_qualifier(QUALIFIER_REGISTER); }
    | AUTO      { $$ = ast_new_qualifier(QUALIFIER_AUTO); }
    | LONG      { $$ = ast_new_qualifier(QUALIFIER_LONG); }
    | SHORT     { $$ = ast_new_qualifier(QUALIFIER_SHORT); }
    | SIGNED    { $$ = ast_new_qualifier(QUALIFIER_SIGNED); }
    | UNSIGNED  { $$ = ast_new_qualifier(QUALIFIER_UNSIGNED); }
    ;

%%

int yyerror(char *s) {
    fprintf(stderr, "Error at line %d: %s\n",yylineno, s);
    return 0;
}

ast_node_t *parse(char* input) {
    yy_scan_string(input);  // Pass the string to the lexer
    yyparse();
    return root;
    yy_delete_buffer(0);
}