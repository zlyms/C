#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>

int main()
{
    int i, j, n;
    n = 0;
    scanf("%d",& n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf("?");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%2d", i);
        }
        if (i < n) 
        {
            printf("\n");
        }
       
    }
    return 0;
}
