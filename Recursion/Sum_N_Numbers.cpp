#include <stdio.h>

int sum(int n)
{

    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

int sum1(int n)
{

    int i, s = 0;

    for (i = 1; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}

int main()
{

    int r;
    r = sum1(5);
    printf("Sum :- %d", r);
}