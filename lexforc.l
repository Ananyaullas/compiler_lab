%{
#include<stdio.h>
extern FILE *yyin;
%}

DIGIT [0-9]
LETTER [a-zA-Z]
ID {LETTER}({LETTER}|{DIGIT})*
NUM {DIGIT}+
FLOAT {DIGIT}+"."{DIGIT}+
WS [\t\n]+

%%
"int"|"float"|"char"|"return"|"if"|"else"|"while"|"for" {printf("KEYWORD: %s\n",yytext);}
{FLOAT} {printf("FLOAT: %s \n",yytext);}
{NUM} {printf("Number: %s\n",yytext);}
{ID} {printf("Identifier: %s\n",yytext);}
"+"|"-"|"*"|"/"|"=="|"="|"<"|">" {printf("Operator: %s\n",yytext);}
"{"|"}"|"["|"]"|"("|")" {printf("Delimiter: %s\n",yytext);}
WS ;
. {printf("Unknown: %s\n",yytext);}
%%
int yywrap()
{
        return 1;
}
int main(int argc,char *argv[])
{
        yyin=fopen(argv[1],"r");
        printf("Lexical Analyze output\n");
        yylex();
        return 0;
}
