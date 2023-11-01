#include <stdio.h>

void main()
{
    int input;
    printf("\nEnter number: ");
    scanf("%d", &input);
    printf("\n");
    
    while(input > 1)
    {
        if(input % 2 == 0)
        {
            input = input / 2;
            printf("%d\n", input);
        }
        else
        {
            input = input * 3 + 1;
            printf("%d\n", input);
        }
    }
}