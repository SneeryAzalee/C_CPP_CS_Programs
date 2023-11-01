#include <stdio.h>

// Make a program that will ask for a number and a number of digits and determine the highest digit.

void main()
{
    int digits, input, largest_digit = 0;
    printf("\n\nEnter number of digit\(s\): ");
    scanf("%d", &digits);
    printf("\nEnter number: ");
    scanf("%d", &input);
    
    for(int i = 0, remainder; i < digits; i++)
    {
        remainder = input % 10;
        input /= 10;
        
        if(remainder > largest_digit)
        {
            largest_digit = remainder;
        }
    }
    printf("\nLargest Digit: %d\n\n", largest_digit);
}