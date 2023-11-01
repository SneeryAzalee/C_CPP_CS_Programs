#include <stdio.h>
// Make a program that will detect if a number is odd or even.
void main()
{
    int input;
    printf("\nEnter number: ");
    scanf("%d", &input);
    
    if(input % 2 == 0)
    {
        printf("\n%d is an even number.\n\n", input);
    }
    else
    {
        printf("\n%d is an odd number.\n\n", input);
    }
}