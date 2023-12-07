#include <stdio.h>
#include <stdlib.h>

// Make a program that will do factorial operations

int main()
{
    // Initialize
    long long input, result;
    
    // Ask for the input
    printf("\n\nEnter input: ");
    scanf("%lld", &input);
    
    // Assign
    result = input;
    
    // Loop through all the numbers until it reaches 1
    for(long long i = input - 1L; i >= 1L; i--)
    {
        result *= i;
    }
    
    // Print result
    printf("\nResult: %lld\n\n", result);
    
    
    return 0;
}