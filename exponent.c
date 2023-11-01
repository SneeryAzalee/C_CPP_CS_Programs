#include <stdio.h>

// Make a program that will do exponential calculations.

int main()
{
    // Introductions
    long long input, num, exponent, result;
    
    // User Input
    printf("\n\nEnter number: ");
    scanf("%lld", &input);
    printf("Enter exponent: ");
    scanf("%lld", &exponent);
    
    // Assignments
    num = input;
    
    // Exponent Calculation
    if(exponent == 0L)
    {
        result = 1L;
    }
    else if(exponent == 1L)
    {
        result = num * 1L;
    }
    else if(exponent > 1L)
    {
        result = num;
        for(long long i = 1L; i < exponent; i++)
        {
            result *= num;
        }
    }
    
    // Print Output
    printf("\n\n%lld to the power of %lld is: %lld\n\n", input, exponent, result);
    
    return 0;
}