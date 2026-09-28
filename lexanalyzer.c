#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "int", "float", "char", "double", "if",
    "else", "while", "for", "return", "void"
};

int isKeyword(char *s)
{
    int i;
    for(i = 0; i < 10; i++)
        if(strcmp(s, keywords[i]) == 0)
            return 1;
    return 0;
}

int main()
{
    FILE *f;
    char c, str[50];
    int i;

    f = fopen("input.c", "r");

    if(f == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    while((c = fgetc(f)) != EOF)
    {
        /* Ignore spaces, tabs and newlines */
        if(isspace(c))
            continue;

        /* Ignore single-line comments */
        if(c == '/')
        {
            char d = fgetc(f);

            if(d == '/')
            {
                while((c = fgetc(f)) != '\n' && c != EOF);
                continue;
            }

            ungetc(d, f);
        }

        /* Identifier or keyword */
        if(isalpha(c) || c == '_')
        {
            i = 0;
            str[i++] = c;

            while((c = fgetc(f)) != EOF &&
                  (isalnum(c) || c == '_'))
                str[i++] = c;

            str[i] = '\0';

            if(c != EOF)
                ungetc(c, f);

            if(isKeyword(str))
                printf("KEYWORD : %s\n", str);
            else
                printf("IDENTIFIER : %s\n", str);
        }

        /* Number */
        else if(isdigit(c))
        {
            i = 0;
            str[i++] = c;

            while((c = fgetc(f)) != EOF && isdigit(c))
                str[i++] = c;

            str[i] = '\0';

            if(c != EOF)
                ungetc(c, f);

            printf("NUMBER : %s\n", str);
        }

        /* Operators */
        else if(c == '+' || c == '-' || c == '*' ||
                c == '/' || c == '=' || c == '<' ||
                c == '>')
        {
            printf("OPERATOR : %c\n", c);
        }

        /* Special symbols */
        else if(c == ';' || c == ',' || c == '(' ||
                c == ')' || c == '{' || c == '}')
        {
            printf("SPECIAL SYMBOL : %c\n", c);
        }
    }

    fclose(f);
    return 0;
}
