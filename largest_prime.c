#include <stdio.h>

// Make a program that will determine the largest prime number of a given number of inputs.

void main()
{
    // Introductions
    int input_counter;
    long long input[99], largest_prime = 0L;
    
    // User Input
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &input_counter);
    printf("\n");
    
    for(int i = 0; i < input_counter; i++)
    {
        printf("%d. ", i + 1);
        scanf("%lld", &input[i]);
    }
    
    // Check individual inputs for the largest prime
    for(int i = 0; i < input_counter; i++)
    {
        int count = 0;
        
        for(long long j = 2L; j < input[i]; j++)
        {
            if(input[i] % j == 0L)
            {
                count++;
            }
        }
        
        if(count == 0)
        {
            if(input[i] > largest_prime && input[i] > 1)
            {
                largest_prime = input[i];
            }
        }
    }
    
    // Print Output
    if(largest_prime == 0)
    {
        printf("\n\nThere are no prime numbers in the given inputs.\n\n");
    }
    else
    {
        printf("\n\nThe largest prime of all the given numbers is: %lld\n\n", largest_prime);
    }    
}