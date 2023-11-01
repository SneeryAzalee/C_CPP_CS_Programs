#include <stdio.h>

// Make a program that will add all the digits from a given number.

int main()
{
    // Introductions
    long long input, remainder, result = 0L;
    
    // User Input
    printf("\n\nEnter a number: ");
    scanf("%lld", &input);
    
    // Calculations
    while(input > 0L)
    {
        remainder = input % 10;
        result += remainder;
        input /= 10;
    }
    
    // Print Result
    printf("\nResult: %lld\n\n", result);
    
    return 0;
}