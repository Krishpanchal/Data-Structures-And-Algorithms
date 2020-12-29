#include <iostream>
using namespace std;

int main()
{

    char string[] = "finding";
    int H[26] = {0}, i;

    for (i = 0; string[i] != '\0'; i++)
    {
        H[string[i] - 97]++;
    }

    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            // printf("%c", i + 97);
            cout << char(i + 97);
            printf(" = %d \n", H[i]);
        }
    }
}