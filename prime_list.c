#include <stdio.h>
#include <stdlib.h>

// Make a program that will list the prime numbers.

void is_Prime(int limit)
{
    int count = 1, num = 2;
    while(count <= limit)
    {
        int prime = 1, output;
        for(int i = 2; i < num; i++)
        {
            output = num % i;
            if(output == 0)
            {
                prime = 0;
                break;
            }
        }
        if(prime == 1)
        {
            printf("\n%d. %d", count, num);
            count++;
        }
        num++;
    }
}

int main()
{
    printf("\nEnter limit: ");
    int input;
    scanf("%d", &input);
    printf("\n");

    is_Prime(input);
    printf("\n");

    return 0;
}