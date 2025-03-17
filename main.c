#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct
{
    string name;
    string number;
}
person;

int GetUserInput();
int PrintSequentialNumbers();
int PrintSequentialNumbersDoWhile();
int PrintEvenNumbers();
int PrintOddNumbers();
int CheckPosNeg();
int LinearSearchNumbers();
int LinearSearchString();
int PhoneBook();
int PhoneBookType();
int ArrayBasics();
int SelectionSort(int array[], int size);
int BubbleSort(int array[], int size);
int BubbleSortOptimized(int array[], int size);
int Pyramid();
void Draw(int n);
void DrawRecursion(int n);
int Recursion();
int BinarySearch(int array[], int element, int left, int right);

int main(void)
{
    // int numbers[] = {3, 2, 7, 1, 4, 5, 8, 0, 9, 6};

    // int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 30, 50};
    int numbers[] = {3, 2, 7, 1, 20, 5, 8, 9, 50, 10, 15, 4, 30, 6, 0};

    int size =  sizeof(numbers) / sizeof(numbers[0]);
    int target = 10;

    BubbleSort(numbers, size);


    // SelectionSort(numbers, size);
    // int index = BinarySearch(numbers, 15, 0, 10);
    // printf("Index of target %d = %d\n", target, index);
}

// Querying user number
int GetUserInput(void)
{
    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);
    return number;
}

int ArrayBasics()
{
    int numbers[] = {2, 15, 1, 30, 4, 15, 80};
    int arrayLength = sizeof(numbers) / sizeof(numbers[0]);
    int LastIndex = arrayLength - 1;
    printf("Array size: %i\n", arrayLength);
    printf("Last Index: %i\n", LastIndex);
    for (int i = 0; i < arrayLength; i++)
    {
        if (LastIndex == i)
        {
            printf("Last Index element: %i\n", numbers[i]);
        }
    }
}

int Recursion()
{
    int height = get_int("Height: ");
    DrawRecursion(height);
}

void DrawRecursion(int n)
{
    if (n <= 0)
    {
        return;
    }
    DrawRecursion(n -1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

int Pyramid()
{
    int height = get_long("Height: ");
    Draw(height);
}

void Draw(const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}

/**
 * Compares two neighbouring elements and swap them if they're in the wrong order
 *Repeat n time; For index i of 0 till n-2, if array[i] and array[i+1] are out of order, swap them
 * n-2 is to prevent out of bounds sorting
*/
int BubbleSort(int array[], int size)
{
    // Outer loop that goes through the looks at the entire array
    for (int i = 0; i < size; i++)
    {
        // Inner loop for looking at adjacent numbers and performing the swap.
        // Compares the last element and avoids overflow
        for (int j = 0; j < (size-1) ; j++)
        {
            // Checks if the current element is greater than the next element
            if (array[j] > array[j + 1])
            {
                /**
                 * Stores the current element into a temporary variable
                 * Assigns the value of the next index element to the current index
                 * Assigns the next index the value stored in the temp variable
                */
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("numbers[%d] = %d\n", i, array[i]);
    }
}

int BubbleSortOptimized(int array[], int size)
{
    bool swapped = false;
    int i = 0;
    do {
        swapped = false;
        for (int j = 0; j < (size-1 - i) ; j++)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    swapped = true;
                }
            }
        i++;
    } while (swapped);
    for (int i = 0; i < size; i++)
    {
        printf("numbers[%d] = %d\n", i, array[i]);
    }
}

/**
 * Finds the smallest element in an array and swaps that element first the first unsorted element
 * For index i of 0 till the last index in an array: Find the smaller num between the first element and last element
 * Swap the smallest of the number in the array with the first element
*/
int SelectionSort(int array[], int size)
{
    int LastSearchIndex = size - 1;
    for (int i = 0; i < LastSearchIndex; i++)
    {
        int minIndex = i;
        // Loops through the unsorted portion to find the index of the smallest item in the array
        // j = i + 1 assumes that the current index in the smallest, therefore skips to the next
        for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[minIndex])
                    {
                        minIndex = j;
                    }
            // Swaps the array elements if necessary
            if (minIndex != i)
            {
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("numbers[%d] = %d\n", i, array[i]);
    }
}

// Binary Search on unsorted list
int BinarySearch(int array[], int element, int left, int right)
{
    // Finds the middle section of the array
    int middle =  left + (right - left) / 2;

    if (left > right)
        {
        return -1;
        }

    if (array[middle] == element)
        {
            return middle;
        }
    else if (array[middle] > element)
        {
        return BinarySearch(array, element, left, middle - 1);
        }
    else
        {
        return BinarySearch(array, element, middle + 1, right);
        }
}

// Linear Search String
int LinearSearchString(void)
{
    string tokens[] = {"battleship", "boots", "cannon", "iron", "thimble", "top hat"};
    string s = get_string("Please enter a string: ");
    int arrayLength = sizeof(tokens) / sizeof(tokens[0]);
    for (int i = 0; i < arrayLength; i++)
        if (strcmp(tokens[i], s) == 0 )
            {
            printf("Token %s found at position: %i\n", tokens[i],i);
            return 0;
            }
    printf("Token not found\n");
    return 1;
}

// Linear Search String
int PhoneBookType(void)
{
    person people[3];

    people[0].name = "ken";
    people[0].number = "080-1234-4567";

    people[1].name = "iroha";
    people[1].number = "080-4567-1234";

    people[2].name = "kanagi";
    people[2].number = "080-9876-5432";

    string name = get_string("Name: ");
    int nameCount = sizeof(people) / sizeof(people[0]);
    for (int i = 0; i < nameCount; i++)
    {
        if (strcmp(people[i].name, name) == 0 )
        {
            printf("Found %s's number %s at position: %i\n", people[i].name, people[i].number,i);
            return 0;
        }
    }
    printf("Name not found\n");
    return 1;
}


int PhoneBook(void)
{
    string names[] = {"ken", "iroha", "kanagi"};
    string numbers[] = {"080-1234-4567", "080-4567-1234", "080-9876-5432"};

    string name = get_string("Name: ");
    int nameCount = sizeof(names) / sizeof(names[0]);
    for (int i = 0; i < nameCount; i++)
    {
        if (strcmp(names[i], name) == 0 )
        {
            printf("Found %s's number %s at position: %i\n", names[i], numbers[i],i);
            return 0;
        }
    }
    printf("Name not found\n");
    return 1;
}

// linear Search Numbers
int LinearSearchNumbers()
{
    int numbers[] = {10, 15, 20, 30, 50, 75, 80};
    int arrayLength = sizeof(numbers) / sizeof(numbers[0]);
    int n = GetUserInput();
    for (int i = 0; i < arrayLength; i++)
    {
        if (numbers[i] == n)
        {
            printf("Number %i found at position: %i\n", numbers[i],i);
            return 0;
        }
    }
    printf("Number not found\n");
    return 1;
}

// For Loops
int PrintSequentialNumbers(void)
{
    int size = GetUserInput();
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", i);
    }
    return 0;
}

// Do While Version
int PrintSequentialNumbersDoWhile(void)
{
    const int size = GetUserInput();
    int i = 0;
    do
    {
        printf("%d \n", i);
        i +=1;
    } while ( i < size);
    return 0;
}

// For Loops
int PrintEvenNumbers(void)
{
    int size = GetUserInput();
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

// For Loops
int PrintOddNumbers(void)
{
    int size = GetUserInput();
    for (int i = 0; i < size; i++)
    {
        if (i % 2 > 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

// Conditionals
int CheckPosNeg(void)
{
   const int size = GetUserInput();
   if (size > 0)
    {
       printf("You have entered a positive number\n");
    }
    else if (size < 0)
    {
        printf("You have entered a negative number\n");
    }
    else
    {
        printf("You have entered 0\n");
    }
    return 0;
}


