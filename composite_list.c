#include <stdio.h>

// Make a program that will list out all the composite numbers.

int main()
{
    // Introductions
    int iterations = 1, limit;
    
    // User Input
    printf("\n\nEnter limit: ");
    scanf("%d", &limit);
    printf("\n");
    
    // Calculate composite numbers
    for(long long i = 4L; iterations <= limit; i++)
    {
        int count = 0;
        
        for(long long j = 2L; j < i; j++)
        {
            if(i % j == 0L)
            {
                count++;
            }
        }
        
        if(count > 0)
        {
            printf("%d. %d\n", iterations, i);
            iterations++;
        }
    }
    
    return 0;
}