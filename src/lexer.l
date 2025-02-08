%{
#include "parser.tab.h"  // Include Bison header to recognize token types
extern int yylval;
%}

%%
[0-9]+          { yylval = atoi(yytext); return NUMBER; }
[ \t\n]         ;  // Ignore whitespace
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
.               { return yytext[0]; }  // Catch-all for unexpected characters
%%

int yywrap() {
    return 1;
}