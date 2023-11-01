#include <stdio.h>

void main()
{
    printf("\n! Fibonacci Sequence (up to 100th term) !\n\n");
    long long first_value = 0L, second_value = 1L, third_value;
    printf("0. 0\n");
    printf("1. 1\n");
    for(long long i = 1L; i < 100L; i++)
    {
        if(i % 2L != 0L)
        {
            third_value = first_value + second_value;
            first_value = third_value;
            printf("%lld. %lld\n", i + 1, third_value);
        }
        else
        {
            third_value = first_value + second_value;
            second_value = third_value;
            printf("%lld. %lld\n", i + 1, third_value);
        }
    }
}