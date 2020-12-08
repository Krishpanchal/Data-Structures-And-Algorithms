#include <stdio.h>
#include <stdlib.h>

//Creating the structure for the array data
struct Array
{
    int A[10];
    int size;   // the complete size of the array
    int length; // how many elements in array
};

void Display(struct Array arr1)
{
    int i;
    printf("\n\n\n Elements are \n");
    for (int i = 0; i < arr1.length; i++)
        printf("[%d] = %d \n", i, arr1.A[i]);
}

//Adding elements at the end
void Append(struct Array *arr1, int x)
{

    if (arr1->length < arr1->size)
    {
        arr1->A[arr1->length] = x;
        arr1->length++;
    }
    else
    {
        printf("No space");
    }
}

void Insert(struct Array *arr1, int index, int value)
{

    //Check length
    if (index >= 0 && index <= arr1->length)
    {
        //traverse from backwards and shift the elements from the index till end
        for (int i = arr1->length; i > index; i--)
        {
            arr1->A[i] = arr1->A[i - 1];
        }
        arr1->A[index] = value;
        arr1->length++;

        Display(*arr1);
    }
    else
    {
        printf("The size of the array is %d so cannot get index %d", arr1->size, index);
    }
}

void Delete(struct Array *arr1, int index)
{

    int x = arr1->A[index];

    for (int i = index; i < arr1->length - 1; i++)
    {
        arr1->A[i] = arr1->A[i + 1];
    }
    arr1->length--;

    Display(*arr1);
    printf(" \n The value %d is deleted from the index %d \n", x, index);
}

int main()
{
    int index;
    // int value;
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    Display(arr);

    printf("The length of array is %d \n", arr.length);
    printf("Enter the index you want to delete: ");
    scanf("%d", &index);

    Delete(&arr, index);

    // Insert(&arr, index, value);

    // Append(&arr, 10);

    return 0;
}