#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    long long input, remainder, result = 0L;
    printf("Enter binary: ");
    scanf("%lld", &input);
    
    for(long long i = 0L; input > 0L; i++)
    {
        remainder = input % 10L;
        if(remainder > 0L)
        {
            result += (long long)pow(2, i);
        }
        input /= 10L;
    }
    
    printf("%lld", result);
}