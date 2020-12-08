#include <stdio.h>

int fact(int n)
{

    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int fact1(int n){

    int f = 1,i;

    for( i = 1; i<= n ; i++){
     f = f * i;
    }
    return f;
}

int main()
{

    int r;
    r = fact1(
    printf("%d \n", r);
}