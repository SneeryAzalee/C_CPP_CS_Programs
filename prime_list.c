#include <stdio.h>

int main()
{
    int limit, iteration = 1;
    printf("\n\nEnter limit: ");
    scanf("%d", &limit);
    printf("\n");
    
    for(long long i = 2L; iteration <= limit; i++)
    {
        int count = 0;
        for(long long j = 2L; j < i; j++)
        {
            if(i % j == 0L)
            {
                count++;
            }
        }
        if(count == 0)
        {
            printf("%d. %lld\n", iteration, i);
            iteration++;
        }
    }
    return 0;
}