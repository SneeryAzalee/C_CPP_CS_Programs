#include <stdio.h>

// Make a program that will get the LCD of two numbers.

void main()
{
    // Introductions
    int input1, input2, highest, lowest, lcd;
    
    // User Input
    printf("\n\nEnter first denominator: ");
    scanf("%d", &input1);
    printf("\nEnter second denominator: ");
    scanf("%d", &input2);
    
    // Assignments
    highest = (input1 > input2) ? input1 : input2;
    lowest = (input1 < input2) ? input1 : input2;
    
    // LCD Identifier
    if(highest % lowest == 0)
    {
        lcd = highest;
        printf("\n\nThe LCD of %d and %d is: %d\n\n", input1, input2, lcd);
    }
    else
    {
        int gcd;
        for(int i = 1; i <= lowest; i++)
        {
            if(input1 % i == 0 && input2 % i == 0)
            {
                gcd = i;
            }
        }
        lcd = (highest * lowest) / gcd;
        printf("\n\nThe LCD of %d and %d is: %d\n\n", input1, input2, lcd);
    }
    
}