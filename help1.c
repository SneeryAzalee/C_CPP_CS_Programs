#include <stdio.h>

int main()
{
    // Get input integer
    printf("\nInput integer: ");
    int inputInteger;
    scanf("%d", &inputInteger);
    
    // Print output
    int previousResult = 0;
    printf("\nOutput: ");
    for(int i = 0; i < inputInteger; i++)
    {
        printf("%d ", previousResult + inputInteger + 1);
        previousResult = previousResult + inputInteger;
    }
    printf("\n");
    
    return 0;
}