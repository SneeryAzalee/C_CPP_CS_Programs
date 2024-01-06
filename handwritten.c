#include <stdio.h>
#include <stdlib.h>

/*
    FINAL TERM • 1ST SEMESTER WRITTEN EXAM
    
    1. Write a program that will swap the whole number and decimal number of an input.
        • Input  >> 123.321 123 123.15 12
        • Output >> 321.123 123 15.123 12
        
    2. Using problem number 1, sort the decimal numbers in ascending order.
        • Input  >> 123.321 123 123.15 12
        • Output >> 123.123 123 123.15 12
        
    3. Write a program that will remove the duplicate digits found in both the whole number and the decimal number of an input.
        • Input  >> 191.976 191 123.434 .123
        • Output >> 11.76   191 12.44   .123
*/

void swap()
{
    
}


void sort()
{
    printf("sort");
}


void duplicate()
{
    printf("duplicate");
}


int main()
{
    // Program selector
    int selector;
    printf("Select a program to execute:\n\n");
    printf("\n1) Program that will swap the whole number and decimal number of an input\n");
    printf("\n2) Program that will sort the decimal numbers in ascending order\n");
    printf("\n3) Program that will remove the duplicate digits found in both the whole number and the decimal number of an input\n");
    printf("\n\n>> ");
    scanf("%d", &selector);
    
    // Evaluate chosen program
    if(selector == 1)
    {
        swap();
    }
    else if(selector == 2)
    {
        sort();
    }
    else if(selector == 3)
    {
        duplicate();
    }
    else
    {
        printf("\nInvalid selection! Try again later.\n");
    }
    
    printf("\n\n");
    
    
    return 0;
}