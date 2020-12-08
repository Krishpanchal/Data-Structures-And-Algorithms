#include <stdio.h>
#include <iostream>

using namespace std;

int f[10]; // global array

int fib(int n)
{

    int t0 = 0, t1 = 1, s = 0, i;

    if (n <= 1)
        return n;

    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int rfib(int n)
{

    if (n <= 1)
        return n;

    return rfib(n - 2) + rfib(n - 1);
}

// Using recursion but by reducing time complexity
int reduFib(int n)
{

    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {

        if (f[n - 2] == -1)
        {
            f[n - 2] = reduFib(n - 2);
        }

        if (f[n - 1] == -1)
        {
            f[n - 1] = reduFib(n - 1);
        }

        f[n] = f[n - 2] + f[n - 1];
        return f[n - 2] + f[n - 1];
    }
}

int main()
{

    for (int i = 0; i <= 10; i++)
        f[i] = -1;

    int n, result;
    cout << "Enter the term number:";
    cin >> n;

    result = reduFib(n);
    printf("%d \n", result);
    return 0;
}