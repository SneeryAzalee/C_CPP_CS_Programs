#include <stdio.h>
#include <stdlib.h>

// Make a program that will express a user input number as a sum of two prime numbers.

int prime(long long input)
{
    // Initialize composite counter
    int count = 0;
    
    // Check if the number is prime
    for(long long i = 2L; i < input; i++)
    {
        if(input % i == 0L)
        {
            count++;
        }
    }
    
    // Return true if the number is prime
    if(count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    // Declare and Initialize
    long long input;
    
    // Ask for input
    printf("\e[1;33m\n\nEnter number: \e[1;35m");
    scanf("%lld", &input);
    printf("\n");
    
    // Loop first number going upwards and second number going downwards up until their differences reach 1 and below
    for(long long i = 2L; i <= (input / 2L); i++)
    {
        for(long long j = 2L; j < input; j++)
        {
            if(i + j == input)
            {
                if(prime(i) && prime(j))
                {
                    printf("\e[1;30m>  \e[1;32m%lld \e[1;36m+ \e[1;32m%lld\n", i, j);
                }
                
                break;
            }
        }
    }
    
    // Reset formatting
    printf("\n\e[0m");
    
    
    return 0;
}