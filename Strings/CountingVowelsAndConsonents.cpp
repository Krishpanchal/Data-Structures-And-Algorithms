#include <iostream>
using namespace std;

int main()
{

    char A[] = "How are     you?";

    int i, vowels = 0, consonents = 0, whiteSpace = 0, words = 0;
    for (i = 0; A[i] != '\0'; i++)
    {

        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            vowels++;
        }
        else if ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122))
        {
            consonents++;
        }

        if (A[i] == ' ')
            whiteSpace++;

        if (A[i] == ' ' && A[i - 1] != ' ')
        {
            words++;
        }
    }

    cout << "Vowels :" << vowels;
    cout << "\n Consonents :" << consonents;
    cout << "\n words :" << words + 1;
    cout << "\n Whitespace :" << whiteSpace;
}
    