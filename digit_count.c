#include <stdio.h>
#include <stdlib.h>

// Make a program that will display how many digits an input have.

int main()
{
    // Declare / Initialize
    int input_count;
    
    // Ask user how many inputs
    printf("\n\n>> Enter number of inputs: ");
    scanf("%d", &input_count);
    printf("\n\n");
    
    // Get inputs and print out their number of digits
    for(int i = 0; i < input_count; i++)
    {
        // Declare / Initialize
        int input, digit_count = 0;
        
        // Get user input
        printf(">> %d. ", i + 1);
        scanf("%d", &input);
        
        // Get the number of digits in input
        while(input > 0)
        {
            input /= 10;
            digit_count++;
        }
        
        // Print number of digits
        printf("\nDigits: %d\n\n", digit_count);
    }
    
    
    return 0;
}