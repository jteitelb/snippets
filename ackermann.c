#include <stdio.h>

int ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n==0)
    {
        return ackermann(m-1, 1);
    }
    else
    {
        return ackermann(m-1, ackermann(m, n-1));
    }
}

int main(void)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d\t", ackermann(i, j));
        }
        printf("\n");
    }
    return 0;
}
