#include <stdio.h>
#include <stdlib.h>

// Make a program that will do Additive Prime Number operations

int main()
{
    // Declare variables
    long long input_count;
    
    // Ask user for number of inputs
    printf("\n\n>> Enter number of inputs: ");
    scanf("%lld", &input_count);
    
    long long additive_prime[input_count];
    
    // Loop as many as the number of inputs
    for(long long i = 0L; i < input_count; i++)
    {
        // Declare variables
        long long input, remainder, temp, reversed = 0L, digit_count = 0L, result = 0L, composite_count = 0L;
        
        // Get input
        printf("\n\n\n>> %lld. ", i + 1L);
        scanf("%lld", &input);
        printf("\n");
        
        // Copy input
        temp = input;
        
        // Reverse input
        while(temp > 0L)
        {
            remainder = temp % 10L;
            reversed = (reversed * 10L) + remainder;
            digit_count++;
            temp /= 10L;
        }
        
        // Print and add all the digits
        for(long long j = 1L; j <= digit_count; j++)
        {
            remainder = reversed % 10L;
            printf("%lld ", remainder);
            
            if(j == digit_count)
            {
                printf("= ");
            }
            else
            {
                printf("+ ");
            }
            
            result += remainder;
            reversed /= 10L;
        }
        
        // Print Result
        printf("%lld ", result);
        
        // If result is < 2
        if(result < 2L)
        {
            composite_count = -1L;
        }
        
        // Check if prime or composite then print
        for(long long j = 2L; j < result; j++)
        {
            if(result % j == 0L)
            {
                composite_count++;
            }
        }
        
        // Evaluate
        if(composite_count == 0L)
        {
            printf("(Prime)\n");
            additive_prime[i] = input;
        }
        else if(composite_count > 0L)
        {
            printf("(Composite)\n");
            additive_prime[i] = 0L;
        }
        else
        {
            printf("(Invalid)\n");
            additive_prime[i] = -1L;
        }
    }
    
    // Count how many valid inputs
    long long valid_counter = 0L;
    for(long long i = 0L; i < input_count; i++)
    {
        if(additive_prime[i] > 0L)
        {
            valid_counter++;
        }
    }
    
    // Print all valid additive prime numbers
    printf("\n\n\nValid Additive Prime Numbers: \n\n");
    for(long long i = 0L; i < input_count && valid_counter > -1L; i++)
    {
        if(additive_prime[i] <= 0L && valid_counter <= 0L && i == 0L)
        {
            printf("NONE");
            valid_counter--;
        }
        else if(additive_prime[i] > 0L && valid_counter > 1L)
        {
            printf("%lld, ", additive_prime[i]);
            valid_counter--;
        }
        else if(additive_prime[i] > 0L && valid_counter == 1L)
        {
            printf("%lld", additive_prime[i]);
            valid_counter--;
        }
    }
    printf("\n\n\n");
    
    
    return 0;
}