%{
#include "parser.tab.h"  
#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern ast_node_t* yylval;
%}

%%
[ \t\n]         ;  // Ignore whitespace
[0-9]+          { yylval = ast_new_integer_literal(strtol(yytext,NULL,10)); return NUMBER; } // integer literal
0x[0-9a-fA-F]+  { yylval = ast_new_integer_literal(strtol(yytext,NULL,16)); return NUMBER; } // hex literal
0o[0-7]+        { yylval = ast_new_integer_literal(strtol(yytext,NULL,8)); return NUMBER; } // octal literal
0b[01]+         { yylval = ast_new_integer_literal(strtol(yytext,NULL,2)); return NUMBER; } // binary literal
";"             { return SEMICOLON;}
"~"             { return NOT; }
"!"             { return LNOT; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return REM; }
"&"             { return AND; }
"|"             { return OR; }
"^"             { return XOR; }
"<<"            { return SHL; }
">>"            { return SHR; }
"&&"            { return LAND; }
"||"            { return LOR; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LCURLY; }
"}"             { return RCURLY; }
"["             { return LSQUARE; }
"]"             { return RSQUARE; }
"."             { return ACCESS; }
"->"            { return POINTER_ACCESS;}
"++"            { return INC; }
"--"            { return DEC; }
"&"             { return ADDROF; }
"="             { return ASS; }
"?"             { return TERNQ; }
":"             { return COLON; }
"+="            { return CHADD; }
"-="            { return CHSUB; }
"*="            { return CHMUL; }
"/="            { return CHDIV; }
"%="            { return CHREM; }
"<<="           { return CHSHL; }
">>="           { return CHSHR; }
"&="            { return CHAND; }
"^="            { return CHXOR; }
"|="            { return CHOR;  }
","             { return COMMA;}
auto            { return AUTO;}
double          { return DOUBLE;}
int             { return INT;}
struct          { return STRUCT;}
break           { return BREAK;}
else            { return ELSE;}
long            { return LONG;}
switch          { return SWITCH;}
case            { return CASE;}
enum            { return ENUM;}
register        { return REGISTER;}
typedef         { return TYPEDEF;}
char            { return CHAR;}
extern          { return EXTERN;}
return          { return RETURN;}
union           { return UNION;}
const           { return CONST;}
float           { return FLOAT;}
short           { return SHORT;}
unsigned        { return UNSIGNED;}
continue        { return CONTINUE;}
for             { return FOR;}
signed          { return SIGNED;}
void            { return VOID;}
default         { return DEFAULT;}
goto            { return GOTO;}
sizeof          { return SIZEOF;}
volatile        { return VOLATILE;}
do              { return DO;}
if              { return IF;}
static          { return STATIC;}
while           { return WHILE;}
_Bool           { return _BOOL;}
_Imaginary      { return _IMAGINARY;}
restrict        { return RESTRICT;}
_Complex        { return _COMPLEX;}
inline          { return INLINE;}

[A-Za-z\u00A1-\u00FF][A-Z0-9a-z\u00A1-\u00FF]+ {
    yylval = ast_new_identifier(strdup(yytext), yyleng);
    return IDENTIFIER;
}

.  { return yytext[0]; }
%%

int yywrap() {
    return 1;
}