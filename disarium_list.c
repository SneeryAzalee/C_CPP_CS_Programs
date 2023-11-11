#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Make a program that will list out all Disarium numbers up to specified limit

int main()
{
    // Declare and initialize variables
    long long limit = 0L, iterations = 0L;
    
    // Ask the user for the limit
    printf("\n\nEnter limit: ");
    scanf("%lld", &limit);
    printf("\n\nDISARIUM NUMBERS:\n\n");
    
    // Cycle through iterations until it reaches the limit
    for(long long i = 0L; iterations < limit; i++)
    {
        // Declare and initialize variables
        long long remainder, reverse = 0L, temp;
        long double result = 0L;
        
        // Copy the input value for calculation
        temp = i;
        
        // Reverse the input
        while(temp > 0L)
        {
            remainder = temp % 10L;
            reverse = (reverse * 10L) + remainder;
            temp /= 10L;
        }
        
        // Get the exponential result for each digit
        for(long long j = 1L; reverse > 0L; j++)
        {
            remainder = reverse % 10L;
            result += pow(remainder, j);
            reverse /= 10L;
        }
        
        // Print if the result matches the input
        if(result == i)
        {
            iterations++;
            printf("%lld. %lld\n", iterations, i);
        }
    }
    
    printf("\n\n");
    
    
    return 0;
}