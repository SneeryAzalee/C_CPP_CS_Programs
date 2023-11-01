#include <stdio.h>

// Make a program that will list out the Armstrong numbers.

int main()
{
    // Introductions
    long long limit, iterations = 1L;
    
    // User Input
    printf("\n\nEnter limit: ");
    scanf("%lld", &limit);
    printf("\n");
    
    // Loop through all the numbers up until the limit
    for(long long k = 0L; iterations <= limit; k++)
    {
        // Introductions
        long long input, main_num, check_digit, digits = 0L, remainder, raw[99], result = 0L;
        
        // Assignments
        input = k;
        check_digit = input;
        main_num = input;
    
        // Get number of digits
        while(check_digit > 0L)
        {
            check_digit /= 10L;
            digits++;
        }
    
        // Get the exponential result for each individual digit
        long long i;
        for(i = 1L; input > 0L; i++)
        {
            remainder = input % 10L;
        
            if(digits == 1L)
            {
                raw[i] = remainder;
            }
            else if(digits > 1L)
            {
                raw[i] = remainder;
                for(long long j = 1L; j < digits; j++)
                {
                    raw[i] *= remainder;
                }
            }
        
            input /= 10L;
        }
        
        // Get result
        for(long long j = i - 1L; j > 0L; j--)
        {
            result += raw[j];
        }
    
        // Evaluate if it's an Armstrong number
        if(result == main_num)
        {
            printf("%lld. %lld\n", iterations, main_num);
            iterations++;
        }
    }
    
    return 0;
}