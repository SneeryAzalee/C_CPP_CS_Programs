#include <stdio.h>
// Identify if a number is a perfect square.
int main()
{
    int input, square, count = 0;
    printf("\nEnter a number: ");
    scanf("%d", &input);
    
    for(int i = 0; i <= input; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i * j == input && i == j)
            {
                square = i;
                printf("\n%d is a perfect square. \( %d \) \n", input, square);
                count++;
            }
        }
    }
    if(count == 0)
    {
        printf("\n%d is not a perfect square.\n", input);
    }
    
    return 0;
}