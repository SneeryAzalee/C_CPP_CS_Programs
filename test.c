#include <stdio.h>

void prob1()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 5; j > i; j--)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void prob2()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j < i)
            {
                printf("  ");
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void prob3()
{
    for(int i = 5; i > 0; i--)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j > (i - 2))
            {
                printf("* ");
            }
            else
            {
                
                printf("  ");
            }
        }
        printf("\n");
    }
}

void prob4()
{
    int input, output = 0, storage = 2;
    
    printf("Input: ");
    scanf("%d", &input);
    printf("\n1 • 1 ");
    
    for(int i = 3; i <= input; i++)
    {
        if(i % 2 == 0)
        {
            output *= 2;
            printf("• %d ", output);
            storage++;
        }
        else
        {
            output += storage;
            printf("• %d ", output);
        }
    }
    printf("\n");
}

void prob5()
{
    int input, previous_odd = 1, previous_even = 1, delay = 2;
    
    printf("Input: ");
    scanf("%d", &input);
    printf("\n1 • 1 ");
    
    for(int i = 3; i <= input; i++)
    {
        if(i % 2 == 0)
        {
            previous_even += 4;
            printf("• %d ", previous_even);
        }
        else
        {
            if(delay == 2)
            {
                delay = 0;
                previous_odd += 1;
            }
            printf("• %d ", previous_odd);
            delay++;
        }
    }
    printf("\n");
}

int main()
{
    int selector;

    printf("\nSelect Problem (1, 2, 3, 4, 5):\n\n>> ");
    scanf("%d", &selector);
    printf("\nOutput:\n\n");

    if(selector == 1)
    {
        prob1();
    }
    else if(selector == 2)
    {
        prob2();
    }
    else if(selector == 3)
    {
        prob3();
    }
    else if(selector == 4)
    {
        prob4();
    }
    else if(selector == 5)
    {
        prob5();
    }
    else
    {
        printf("\nInvalid input!\n\n");
    }

    return 0;
}