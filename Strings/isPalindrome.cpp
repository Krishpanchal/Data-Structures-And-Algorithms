#include <iostream>
using namespace std;

int main()
{

    char A[] = "madam";

    // ****  1st method  ***
    // char B[10];

    // int i, j;

    // for (i = 0; A[i] != '\0'; i++)
    // {
    // }

    // i = i - 1;

    // for (j = 0; i >= 0; j++, i--)
    // {
    //     B[j] = A[i];
    // }
    // B[j] = '\0';

    // for (i = 0, j = 0; A[i] != '\0' && B[i] != '\0'; i++, j++)
    // {
    //     if (A[i] != B[i])
    //         break;
    // }

    // if (A[i] != B[i])
    //     cout << "Not Palindrome";
    // else
    //     cout << "Palindrome";

    //**** Second method*****
    int i, j;

    for (j = 0; A[j] != '\0'; j++)
    {
    }

    j = j - 1;

    for (i = 0; i < j; i++, j--)
    {

        if (A[i] != A[j])
            break;
    }

    cout << i << " " << j;
    if (A[i] == A[j])
        cout << "Palindrome";
    else
        cout << "Not palindrome";
}