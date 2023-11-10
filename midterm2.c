#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long input_count;
    
    printf("\n\nEnter number of inputs: ");
    scanf("%lld", &input_count);
    printf("\n\n");
    
    long long special_numbers[input_count + 1L];
    
    for(long long i = 1L; i <= input_count; i++)
    {
        long long input, input2, remainder, result = 0L;
        
        printf("%lld. ", i);
        scanf("%lld", input);
        
        input2 = input;
        
        for(long long j = 1L; input > 0L; j++)
        {
            remainder = input % 10L;
            result += pow(remainder, j);
            input /= 10L;
        }
        
        if(result == input2)
        {
            special_numbers[i] = result;
        }
    }
    
    printf("\n\nThe special numbers are: ");
    
    for(long long i = 1L; i <= input_count; i++)
    {
        printf("%lld ", special_numbers[i]);
    }
    
    
    return 0;
}