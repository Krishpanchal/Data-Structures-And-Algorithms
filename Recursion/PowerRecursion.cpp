#include <stdio.h>

int power(int m, int n)
{

    if (n == 0)
        return 1;
    else
        return power(m, n - 1) * m;
}

int power1(int m, int n)
{

    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power1(m * m, n / 2);
    else
        return m * power1(m * m, (n - 1) / 2);
}

int power2(int m, int n)
{

    int s = 1;
    for (int i = 1; i <= n; i++)
    {
        s = s * m;
    }
    return s;
}

int main()
{
    int r;
    r = power2(2, 9);
    printf("%d \n", r);
    return 0;
}