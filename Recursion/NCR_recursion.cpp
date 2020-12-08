#include <stdio.h>

int fact(int n)
{

    if (n == 0)
        return 1;

    return fact(n - 1) * n;
}

int NCR(int n, int r)
{

    int num, den;

    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

int NCR_1(int n, int r)
{

    if (n == r || r == 0)
        return 1;

    return NCR_1(n - 1, r - 1) + NCR_1(n - 1, r);
}

int main()
{

    printf("%d ", NCR_1(5, 2));
    return 0;
}