#include <stdio.h>
/* Largest Prime Number of 6 given numbers. */
int main()
{
    int input[] = {10, 23, 6, 11, 2, 23},
        num, largest_prime = -1;
    for(int i = 0; i < 6; i++)
    {
        num = input[i];
        printf("%d ", num);
        
        for(int j = 2; j <= num / 2; j++)
        {
            if(num % j == 0)
            {
                break;
            }
            else
            {
                if(num > largest_prime)
                {
                    largest_prime = num;
                }
            }
        }
    }
    printf("\n\nThe largest prime number out of the given set of numbers is %d\n",
        largest_prime);
    
    return 0;
}