%{
#include<stdio.h>
%}
%%
abc {printf("ABC");}
.|\n {ECHO;}
%%

int yywrap()
{
        return 1;
}
int main()
{
        printf("Enter the input\n");
        yylex();
        return 0;
}
