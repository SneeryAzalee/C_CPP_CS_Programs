#include <stdio.h>
#include <stdlib.h>

// Make a program that will reverse the number if the input is a pronic number. Otherwise, print normally.

int main()
{
    // Declare / Initialize
    long long input_count;
    
    // Ask for how many inputs
    printf("\n\nEnter number of inputs: ");
    scanf("%lld", &input_count);
    printf("\n\nEnter inputs: ");
    
    // Loop for how many inputs
    for(long long i = 0L; i < input_count; i++)
    {
        // Declare / Initialize
        long long input, pronic = 0L, remainder, reversed = 0L;
        
        // Ask for input
        scanf("%lld", &input);
        
        // Print template (execute once)
        if(i == 0L)
        {
            printf("\n\nOutput: ");
        }
        
        // Loop through all consecutive numbers up to the input
        for(long long i = 1L; i <= input; i++)
        {
            // If the product matches the input
            if((i - 1L) * i == input)
            {
                pronic = 1L;
            }
            // If the product of the two consecutive numbers is greater than the input
            else if((i - 1L) * i > input)
            {
                break;
            }
        }
        
        // If the input is a pronic number
        if(pronic == 1L)
        {
            // Reverse the input number
            while(input > 0L)
            {
                remainder = input % 10L;
                reversed = (reversed * 10L) + remainder;
                input /= 10L;
            }
            
            // Only print if the reversed number has a value
            if(reversed > 0L)
            {
                printf("%lld ", reversed);
            }
        }
        // If the input is NOT a pronic number
        else if(pronic == 0L)
        {
            printf("%lld ", input);
        }
    }
    
    printf("\n\n");
    
    
    return 0;
}