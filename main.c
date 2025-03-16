#include <stdio.h>

int GetUserInput();
int PrintSequentialNumbers();
int PrintSequentialNumbersDoWhile();
int PrintEvenNumbers();
int PrintOddNumbers();
int CheckPosNeg();
int SumOfNNumbers();
int MultiplicationTable();
int FactorialNUmber();
void PrintPattern();
int GetLength();
int ReverseNumbers();
int CheckPrimeNumbers();


int main(void)
{
    // PrintSequentialNumbers();
    return 0;
}







// Querying user input
int GetUserInput(void)
{
    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);
    return number;
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

// Arrays

