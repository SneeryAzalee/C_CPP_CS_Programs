#include <stdio.h>

int prime(int input)
{
    int currentPrime = 2, currentIndex = 1;

    for( ; currentIndex <= input; )
    {
        int isPrime = 1;
        for(int j = 2; j < currentPrime; j++)
        {
            if(currentPrime % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
        {
            currentIndex++;
        }
        currentPrime++;
    }

    return currentPrime - 1;
}

int main()
{
    int input;
    printf("\nInput: ");
    scanf("%d", &input);

    printf("\n\nOutput:\n\n");
    if(input % 2 == 1)
    {
        for(int i = 1; i <= input; i++)
        {
            int temp = input;
            for(int j = 1; j <= i; j++)
            {
                printf("%d ", prime(temp--));
            }
            printf("\n");
        }
    }
    else
    {
        int spaces = 0;
        int temp = input;

        for(int i = input; i >= 1; i--)
        {
            int temp2 = temp--;

            int temp3 = temp2;
            for(int j = 1; j <= i + 1; j++)
            {
                if(j == 1)
                {
                    for(int j = 1; j <= spaces; j++)
                    {
                        printf(" ");
                    }
                }
                else
                {
                    printf("%d ", prime(temp3--));
                }
            }

            temp3 = prime(temp2);
            while(temp3 > 0)
            {
                spaces++;
                temp3 /= 10;
            }
            spaces++;
            printf("\n");
        }
    }
    
    printf("\n\n");

    return 0;
}