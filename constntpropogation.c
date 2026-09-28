#include <stdio.h>

int main()
{
    int n, val[26] = {0};
    char s[20], lhs, x, y, op;
    int num;

    printf("Enter the no. of statements: ");
    scanf("%d", &n);

    printf("Enter the statements\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%s", s);

        lhs = s[0];

        /* x = number */
        if(sscanf(s, "%c=%d", &lhs, &num) == 2)
        {
            val[lhs - 'a'] = num;
        }

        /* x = y op z */
        else if(sscanf(s, "%c=%c%c%c", &lhs, &x, &op, &y) == 4)
        {
            int a, b;

            if(x >= '0' && x <= '9')
                a = x - '0';
            else
                a = val[x - 'a'];

            if(y >= '0' && y <= '9')
                b = y - '0';
            else
                b = val[y - 'a'];

            if(op == '+')
                val[lhs - 'a'] = a + b;

            else if(op == '-')
                val[lhs - 'a'] = a - b;

            else if(op == '*')
                val[lhs - 'a'] = a * b;

            else if(op == '/')
                val[lhs - 'a'] = a / b;
        }

        /* x = y */
        else if(sscanf(s, "%c=%c", &lhs, &x) == 2)
        {
            val[lhs - 'a'] = val[x - 'a'];
        }
    }

    printf("After constant propagation:\n");

    for(int i = 0; i < 26; i++)
    {
        if(val[i] != 0)
            printf("%c=%d\n", 'a' + i, val[i]);
    }

    return 0;
}





