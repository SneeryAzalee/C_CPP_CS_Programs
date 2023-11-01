#include <stdio.h>

// Make a program that will print out the value of pi according to user's chosen iterations.

void main()
{
    long long iterations;
    long double result = 0.0L;
    
    printf("\n\nEnter the number of iterations for π: ");
    scanf("%lld", &iterations);
    
    for(long long i = 1L; i <= iterations; i++)
    {
        if(i % 2L == 0L)
        {
            result -= 1.0L / (2.0L * i - 1.0L);
        }
        else
        {
            result += 1.0L / (2.0L * i - 1.0L);
        }
    }
    result *= 4.0L;
    printf("\n\nπ = %.20Lf\n\n", result);
}