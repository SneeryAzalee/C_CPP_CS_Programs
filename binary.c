#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long input, remainder, result = 5L, digit_count = 1L;
    
    printf("\n\nEnter decimal: ");
    scanf("%lld", &input);
    printf("\n\nBinary: ");
    
    if(input == 0L)
    {
        printf("0");
    }
    
    while(input > 0L)
    {
        remainder = input % 2L;
        result = (result * 10L) + remainder;
        input /= 2L;
        digit_count++;
    }
    
    for(long long i = 1L; i < digit_count; i++)
    {
        remainder = result % 10L;
        printf("%lld", remainder);
        result /= 10L;
    }
    
    printf("\n\n");
    
    
    return 0;
}