%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

input:
      expr '\n'  { printf("Result = %d\n", $1); }
    ;

expr:
      expr '+' expr       { $$ = $1 + $3; }
    | expr '-' expr       { $$ = $1 - $3; }
    | expr '*' expr       { $$ = $1 * $3; }
    | expr '/' expr       { $$ = $1 / $3; }
    | '(' expr ')'        { $$ = $2; }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | NUMBER              { $$ = $1; }
    ;

%%

void yyerror(char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}
