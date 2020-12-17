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

// Revesing using auxillary array
// void Reverse(struct Array *arr1)
// {

//     int *B;
//     int i, j;

//     B = (int *)malloc(arr1->length * sizeof(int));

//     for(i = arr1->length - 1, j = 0; i >= 0; i-- ,j++)
//         B[j] = arr1->A[i];

//     for (i = 0; i < arr1->length; i++)
//         arr1->A[i] = B[i];

//     Display(*arr1);
// }

//Reversing from start to end wothout auxillary array

void Reverse(struct Array *arr1)
{
    int i, j;
    for (i = 0, j = arr1->length - 1; i < j; i++, j--)
    {
        swap(&arr1->A[i], &arr1->A[j]);
    }

    Display(*arr1);
}

//
//
//
//
//
//

bool isSorted(struct Array arr1)
{

    int i = 0;

    for (i = 0; i < arr1.length; i++)
    {

        if (arr1.A[i] > arr1.A[i + 1])
        {
            return false;
        }
    }
    return true;
}

//
//
//
//
//
//

void InsertInSorted(struct Array *arr1, int value)
{
    int i = arr1->length - 1;

    if (i >= 0 && arr1->length < arr1->size)
    {

        while (arr1->A[i] > value)
        {

            arr1->A[i + 1] = arr1->A[i];
            i--;
        }

        arr1->A[i + 1] = value;
        arr1->length++;

        Display(*arr1);
    }
    else
    {
        printf("No space");
    }
}

//
//
//
//
//
//

//Placing all -ve elemnts on left side

void ReArrange(struct Array *arr1)
{
    int i = 0;
    int j = arr1->length - 1;

    while (i < j)
    {
        while (arr1->A[i] < 0)
        {
            i++;
        }
        while (arr1->A[j] > 0)
        {
            j--;
        }

        if (i < j)
            swap(&arr1->A[i], &arr1->A[j]);
    }

    Display(*arr1);
}

//
//
//
//
//
//

struct Array *Merge(struct Array arr1, struct Array arr2)
{

    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    //Merge part
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++]; //first assign and then increment
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->size = arr1.size + arr2.size;
    arr3->length = arr1.length + arr2.length;

    return arr3;
}

//
//
//
//
//
//

struct Array *Union(struct Array arr1, struct Array arr2)
{

    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    //Merge part
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++]; //first assign and then increment
        else if (arr2.A[j] < arr1.A[i])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->size = arr1.size + arr2.size;
    arr3->length = k;

    return arr3;
}

//
//
//
//
//
//

struct Array *Intersect(struct Array arr1, struct Array arr2)
{

    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    //Merge part
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else if (arr1.A[i] == arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3->size = arr1.size + arr2.size;
    arr3->length = k;

    return arr3;
}

//
//
//
//
//
//

struct Array *Difference(struct Array arr1, struct Array arr2)
{

    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    //Merge part
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++]; //first assign and then increment
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    arr3->size = arr1.size + arr2.size;
    arr3->length = k;

    return arr3;
}

//
//
//
//
//
//

void LeftShift(struct Array *arr)
{

    int i = 0;
    for (i = 0; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->length - 1] = 0;

    Display(*arr);
}

//
//
//
//
//
//
//

void RightShift(struct Array *arr)
{
    int i;
    for (i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
    arr->A[0] = 0;

    Display(*arr);
}

//
//
//
//
//
//

void LeftRotate(struct Array *arr)
{
    int i, firstVal = arr->A[0];

    for (i = 0; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->length - 1] = firstVal;

    Display(*arr);
}

void RightRotate(struct Array *arr)
{
    int i, lastVal = arr->A[arr->length - 1];

    for (i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
    arr->A[0] = lastVal;

    Display(*arr);
}

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

            "\n\n **************** Some more Operations **************"

            "\n\n 12. Reverse the array"
            "\n 13. Inserting value in a sorted array (only adds in a sorted array)"
            "\n 14. Check if the array is sorted"
            "\n 15. ReArrange the array based on -ve values on left & +ve values on right"
            "\n 16. Merge two arrays (both arrays should be sorted)"

            "\n\n **************** Set Operations **************"
            "\n 17. Union of two arrays(sorted)"
            "\n 18. Intersection of two arrays(sorted)"
            "\n 19. Difference of two arrays(sorted)"

            "\n\n **************** Shift Operations ************"
            "\n 20. Left shift"
            "\n 21. Right Shift"

            "\n\n **************** Rotatte Operations ************"
            "\n 22. Left rotate"
            "\n 23. Right rotate"

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

        case 12:
            Reverse(&arr);

        case 13:
            if (isSorted(arr))
            {
                int valueToInsert;
                printf("Enter the value you want to insert in a sorted array: ");
                scanf("%d", &valueToInsert);

                InsertInSorted(&arr, valueToInsert);
            }

        case 14:
        {
            bool sortedArray = isSorted(arr);
            (sortedArray) ? printf("The given array with %d elements is sorted", arr.length) : printf("The given array with %d elements is not sorted", arr.length);
        }
        break;

        case 15:
            ReArrange(&arr);
            break;

        case 16:
        {
            struct Array arr2;
            struct Array *arr3;

            int n, i;
            //input the size
            printf("Enter the size of the second Array :- ");
            scanf("%d", &arr2.size);

            // creating the array in heap
            arr2.A = (int *)malloc(arr2.size * sizeof(int));

            //input the length
            printf("Enter the number of elements for %d sized second array :- ", arr2.size);
            scanf("%d", &n);

            //check if the length > size
            if (n > arr2.size)
            {
                printf("The number of elements should not be greater than the size of array");
                return 0;
            }

            arr2.length = n;

            //input the elements of the array till the length
            printf("Enter %d elements in the second array:\n", n);

            for (i = 0; i < n; i++)
            {
                printf("\nData in location %d :- ", i);
                scanf("%d", &arr2.A[i]);
            }

            //displaying the elements
            Display(arr2);

            arr3 = Merge(arr, arr2);
            Display(*arr3);
        }
        break;

        case 17:
        {
            struct Array arr2;
            struct Array *arr3;

            int n, i;
            //input the size
            printf("Enter the size of the second Array :- ");
            scanf("%d", &arr2.size);

            // creating the array in heap
            arr2.A = (int *)malloc(arr2.size * sizeof(int));

            //input the length
            printf("Enter the number of elements for %d sized second array :- ", arr2.size);
            scanf("%d", &n);

            //check if the length > size
            if (n > arr2.size)
            {
                printf("The number of elements should not be greater than the size of array");
                return 0;
            }

            arr2.length = n;

            //input the elements of the array till the length
            printf("Enter %d elements in the second array:\n", n);

            for (i = 0; i < n; i++)
            {
                printf("\nData in location %d :- ", i);
                scanf("%d", &arr2.A[i]);
            }

            //displaying the elements
            Display(arr2);

            arr3 = Union(arr, arr2);
            Display(*arr3);
        }
        break;

        case 18:
        {
            struct Array arr2;
            struct Array *arr3;

            int n, i;
            //input the size
            printf("Enter the size of the second Array :- ");
            scanf("%d", &arr2.size);

            // creating the array in heap
            arr2.A = (int *)malloc(arr2.size * sizeof(int));

            //input the length
            printf("Enter the number of elements for %d sized second array :- ", arr2.size);
            scanf("%d", &n);

            //check if the length > size
            if (n > arr2.size)
            {
                printf("The number of elements should not be greater than the size of array");
                return 0;
            }

            arr2.length = n;

            //input the elements of the array till the length
            printf("Enter %d elements in the second array:\n", n);

            for (i = 0; i < n; i++)
            {
                printf("\nData in location %d :- ", i);
                scanf("%d", &arr2.A[i]);
            }

            //displaying the elements
            Display(arr2);

            arr3 = Intersect(arr, arr2);
            Display(*arr3);
        }
        break;

        case 19:
        {
            struct Array arr2;
            struct Array *arr3;

            int n, i;
            //input the size
            printf("Enter the size of the second Array :- ");
            scanf("%d", &arr2.size);

            // creating the array in heap
            arr2.A = (int *)malloc(arr2.size * sizeof(int));

            //input the length
            printf("Enter the number of elements for %d sized second array :- ", arr2.size);
            scanf("%d", &n);

            //check if the length > size
            if (n > arr2.size)
            {
                printf("The number of elements should not be greater than the size of array");
                return 0;
            }

            arr2.length = n;

            //input the elements of the array till the length
            printf("Enter %d elements in the second array:\n", n);

            for (i = 0; i < n; i++)
            {
                printf("\nData in location %d :- ", i);
                scanf("%d", &arr2.A[i]);
            }

            //displaying the elements
            Display(arr2);

            arr3 = Difference(arr, arr2);
            Display(*arr3);
        }
        break;

        case 20:
            LeftShift(&arr);
            break;

        case 21:
            RightShift(&arr);
            break;

        case 22:
            LeftRotate(&arr);
            break;

        case 23:
            RightRotate(&arr);
            break;

        default:
            printf("No number present");
            break;
        }

        printf("\n\nDo you want to redo \n If yes, enter 1 else 0 \n");
        scanf("%d", &willContinue);
    }

    return 0;
}