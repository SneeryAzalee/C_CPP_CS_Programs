#include <stdio.h>

// Make a program that will get the GCD of two numbers.

void main()
{
    // Introductions
    int input1, input2, gcd, lowest_num;
    
    // User Input
    printf("\n\nEnter first number: ");
    scanf("%d", &input1);
    printf("\nEnter second number: ");
    scanf("%d", &input2);
    
    // Assignments
    lowest_num = (input1 < input2) ? input1 : input2;
    
    // GCD Identifier
    for(int i = 1; i <= lowest_num; i++)
    {
        if(input1 % i == 0 && input2 % i == 0)
        {
            gcd = i;
        }
    }
    
    // Print GCD
    printf("\n\nThe GCD of %d and %d is: %d\n\n", input1, input2, gcd);
}