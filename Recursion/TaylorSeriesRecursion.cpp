#include <stdio.h>

double e(int x, int n)
{

    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;

    r = e(x, n - 1);

    p = p * x;
    f = f * n;

    return r + p / f;
}

//talyor series shortened using recursion

double e1(int x, int n)
{
    static double s = 1;

    if (n == 0)
        return s;

    //s = 1 + double(x / n) * s;
    // Without typcasting
    s = 1 + x * s / n;
    return e(x, n - 1);
}

int main()
{

    printf("%1f \n", e1(4, 15));
    return 0;
}