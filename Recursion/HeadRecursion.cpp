#include <stdio.h>

void fun(int n)
{

    if (n > 0)
    {

        fun(n - 1);       //Head recursion
        printf("%d ", n); // gets printed in the returning phase
    }
}

int main()
{

    int x = 3;
    fun(x);
}