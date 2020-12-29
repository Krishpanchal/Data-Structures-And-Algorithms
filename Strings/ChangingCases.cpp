#include <iostream>
using namespace std;

int main()
{

    char A[50];
    cout << "Enter a string :-";
    cin >> A;

    /// To UpperCase
    // for (int i = 0; A[i] != '\0'; i++)
    // {
    //     A[i] = A[i] + 32;
    // }

    // To LowerCase
    // for (int i = 0; A[i] != '\0'; i++)
    // {
    //     A[i] = A[i] - 32;
    // }
    // cout << A;

    // Toggle Cases
    // for (int i = 0; A[i] != '\0'; i++)
    // {

    //     if (A[i] >= 65 && A[i] <= 90)
    //         A[i] += 32;
    //     else if (A[i] >= 'a' && A[i] <= 122)
    //         A[i] -= 32;
    // }
    // cout << A;

    //Even index to upper case

    for (int i = 0; A[i] != '\0'; i++)
    {

        if (i % 2 == 0)
        {
            A[i] = A[i] - 32;
        }
    }
    cout << A;
}
