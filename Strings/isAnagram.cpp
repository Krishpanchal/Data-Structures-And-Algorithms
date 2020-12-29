#include <iostream>
using namespace std;

int main()
{

    char A[] = "decimal";
    char B[] = "medical";
    int H[26] = {0}, i;

    for (i = 0; A[i] != '\0'; i++)
        H[A[i] - 97]++;

    for (i = 0; B[i] != '\0'; i++)
    {
        H[A[i] - 97]--;
        if (H[A[i]] < 0)
        {
            printf("Not Anagram");
            break;
        }
    }
    if (A[i] == '\0')
    {
        printf("Is Anagram");
    }
}