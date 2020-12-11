#include <stdio.h>
#include <stdlib.h>

//Creating the structure for the array data

struct Array
{
    int *A;
    int size;   // the complete size of the array
    int length; // how many elements in array
};

//
//
//
//
//
//

void Display(struct Array arr1)
{
    int i;
    printf("\n\n\n Elements are \n");
    for (int i = 0; i < arr1.length; i++)
        printf("[%d] = %d \n", i, arr1.A[i]);
}

//Adding elements at the end of the aray
void Append(struct Array *arr1, int value)
{

    if (arr1->length < arr1->size)
    {
        arr1->A[arr1->length] = value;
        arr1->length++;

        Display(*arr1); //dereferencing of pointer
    }
    else
    {
        printf("No space in array");
    }
}

//
//
//
//
//
//

//Inserting elements at a particular index
void Insert(struct Array *arr1, int index, int value)
{

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
        printf("No index \n");
    }
}

//
//
//
//
//
//
//

void Delete(struct Array *arr1, int index)
{

    if (index >= 0 && index < arr1->length)
    {

        int x = arr1->A[index];

        for (int i = index; i < arr1->length - 1; i++)
        {
            arr1->A[i] = arr1->A[i + 1];
        }
        arr1->length--;
        Display(*arr1);

        printf("\n\nThe value %d is deleted from the index %d", x, index);
    }
    else
    {
        printf("The index %d doesn;t have any value", index);
    }
}

//helpfull function swap

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//
//
//
//
//
//
//

int LinearSearch(struct Array *arr1, int key)
{

    for (int i = 0; i < arr1->length; i++)
    {

        if (key == arr1->A[i])
        {

            //Improving Linear Search
            //1. Trasposition
            // swap(&arr1->A[i], &arr1->A[i - 1]);

            //2. Move to Front/ Head
            swap(&arr1->A[i], &arr1->A[0]);
            return i;
        }
    }
    return -1;
}

//
//
//
//
//
//

int BinarySearch(struct Array arr1, int key)
{

    int l = 0;
    int h = arr1.length - 1;

    while (h >= 1)
    {

        int mid = (l + h) / 2;

        if (key == arr1.A[mid])
            return mid;

        else if (key < arr1.A[mid])
            h = mid - 1;

        else
            l = mid + 1;
    }

    return -1; //If value not found in array
}

//
//
//
//
//
//
//
//
//

void get(struct Array arr1, int index)
{
    if (index >= 0 && index < arr1.length)
    {
        printf("The element at index %d is %d", index, arr1.A[index]);
    }
    else
    {
        printf("Invalid index");
    }
}

//
//
//
//

void set(struct Array *arr1, int index, int value)
{
    if (index >= 0 && index < arr1->length)
    {
        arr1->A[index] = value;
        Display(*arr1);
    }
    else
    {
        printf("Invalid index");
    }
}

//
//
//
//
//

void Max(struct Array arr1)
{

    int max = arr1.A[0];
    int i;
    for (i = 1; i < arr1.length; i++)
    {
        if (arr1.A[i] > max)
        {
            max = arr1.A[i];
        }
    }

    printf("The max element of all the elements is %d", max);
}

//
//
//
//
//

void Min(struct Array arr1)
{

    int min = arr1.A[0];
    int i;
    for (i = 1; i < arr1.length; i++)
    {
        if (arr1.A[i] < min)
        {
            min = arr1.A[i];
        }
    }

    printf("The max element of all the elements is %d", min);
}

//
//
//
//
//

int sum(struct Array arr1)
{

    int sum = 0;
    int i;
    for (i = 0; i < arr1.length; i++)
    {
        sum += arr1.A[i];
    }

    return sum;
}

//
//
//
//
//

float avg(struct Array arr1)
{
    return (float)sum(arr1) / arr1.length;
}

//
//
//
//
//

int main()
{

    //creating the struct obj
    struct Array arr;

    int n, i;
    //input the size
    printf("Enter the size of the array :- ");
    scanf("%d", &arr.size);

    // creating the array in heap
    arr.A = (int *)malloc(arr.size * sizeof(int));

    //input the length
    printf("Enter the number of elements for %d sized array :- ", arr.size);
    scanf("%d", &n);

    //check if the length > size
    if (n > arr.size)
    {
        printf("The number of elements should not be greater than the size of array");
        return 0;
    }

    arr.length = n;

    //input the elements of the array till the length
    printf("Enter %d elements in the array:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("\nData in location %d :- ", i);
        scanf("%d", &arr.A[i]);
    }

    //displaying the elements
    Display(arr);

    int willContinue = 1;

    while (willContinue == 1)
    {

        int choice;
        printf(
            "\n\nWhich operation you want to do ??:"
            "\n\n 1. Append "
            "'\n 2. Insert in index"
            "\n 3. Delete Value from index "
            "\n 4. Search element by value in array "
            "\n 5. Display Array "
            "\n 6. Get an element through the index"
            "\n 7. Set a value in any index"
            "\n 8. Get the maximum value in the array"
            "\n 9. Get the minimum value in the array"
            "\n 10. Get the sum of all the elements in the array"
            "\n 11. Get the average of the elements in the array"
            "\n\n Enter the number:- ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            int no;
            printf("Enter the value you want to append :-");
            scanf("%d", &no);

            Append(&arr, no);
            break;

        case 2:
            int index, value;
            printf("The current length of the array is %d \n", arr.length);
            printf("Enter the index of storing the value :- ");
            scanf("%d", &index);

            printf("Enter the value :- ");
            scanf("%d", &value);

            Insert(&arr, index, value);
            break;

        case 3:
            int indexNo;
            printf("The current length of the array is %d \n", arr.length);
            printf("Enter the index no you want to delete : ");
            scanf("%d", &indexNo);

            Delete(&arr, indexNo);
            break;

        case 4:
        {
            int searchChoice;
            printf("\n\n Through which method you want to perform search operation \n 1. Linear Search \n 2. Binary Sarch \n\n Enter the number :-");
            scanf("%d", &searchChoice);

            switch (searchChoice)
            {
            case 1:
            {
                //Wraped the case with the parentheses as error occurred
                int searchKey;
                printf("\nEnter the value you want to search: ");
                scanf("%d", &searchKey);

                int foundIndex = LinearSearch(&arr, searchKey);
                if (foundIndex == -1)
                {
                    printf("\nThe value %d in not present in array \n", foundIndex);
                }
                else
                {
                    printf(" \n The value %d is present in index no. %d \n", searchKey, foundIndex);
                }
                break;
            }

            case 2:
            {
                int searchKey;
                printf("\nEnter the value you want to search: ");
                scanf("%d", &searchKey);

                int foundIndex = BinarySearch(arr, searchKey);
                if (foundIndex == -1)
                {
                    printf("\nThe value %d in not present in array \n", foundIndex);
                }
                else
                {
                    printf(" \n The value %d is present in index no. %d \n", searchKey, foundIndex);
                }
                break;
            }

            default:
                break;
            }
        }
        break;

        case 5:
            Display(arr);
            break;

        case 6:
            int getIndex;
            printf("Enter the valid index for getting the value in it :");
            scanf("%d", &getIndex);

            get(arr, getIndex);

            break;

        case 7:
            int setIndex, setValue;
            printf("Enter the valid index for setting the value :");
            scanf("%d", &setIndex);
            printf("Enter the value to be inserted in the index :");
            scanf("%d", &setValue);

            set(&arr, setIndex, setValue);

            break;

        case 8:
            Max(arr);

            break;

        case 9:
            Min(arr);

            break;

        case 10:
        {
            int allSum = sum(arr);
            printf("The sum of all the elements in the array is %d ", allSum);
            break;
        }

        case 11:
        {
            int average = avg(arr);
            printf("The sum of all the elements in the array is %d ", average);
            break;
        }

        default:
            printf("No number present");
            break;
        }

        printf("\n\nDo you want to redo \n If yes, enter 1 else 0 \n");
        scanf("%d", &willContinue);
    }

    return 0;
}

// printf("The sum of all the elements is %d " , sum);