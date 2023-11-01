#include <stdio.h>

// Make a program that will reverse a number. If the reversed number is prime, find the lowest digit, else, highest digit.

int main()
{
    // Introductions
    long long input, remainder, reversed = 0L, prime_count = 0L, lowest = 9L, highest = 0L;
    
    // User Input
    printf("\n\nEnter a number: ");
    scanf("%lld", &input);
    
    // Reverse Number
    while(input > 0L)
    {
        remainder = input % 10L;
        reversed = (reversed * 10L) + remainder;
        input /= 10L;
    }
    
    // Prime / Composite Calculator
    for(long long i = 2L; i < reversed; i++)
    {
        if(reversed % i == 0L)
        {
            prime_count++;
        }
    }
    
    // Evaluate if its prime or composite
    if(prime_count > 0L && reversed > 1L)
    {
        printf("\nReversed: %lld ", reversed);
        printf("\(Composite\)\n");
        
        // Get the highest reversed number digit
        while(reversed > 0L)
        {
            remainder = reversed % 10L;
            
            if(remainder > highest)
            {
                highest = remainder;
            }
            
            reversed /= 10L;
        }
        
        printf("\nHighest Digit: %lld\n\n", highest);
        
    }
    else if(prime_count == 0L && reversed > 1L)
    {
        printf("\nReversed: %lld ", reversed);
        printf("\(Prime\)\n");
        
        // Get the lowest reversed number digit
        while(reversed > 0L)
        {
            remainder = reversed % 10L;
            
            if(remainder < lowest)
            {
                lowest = remainder;
            }
            
            reversed /= 10L;
        }
        
        printf("\nLowest Digit: %lld\n\n", lowest);
    }
    else
    {
        printf("\nReversed: %lld ", reversed);
        printf("\(Number is less than 2, cannot evaluate!\)\n\n");
    }
    
    return 0;
}