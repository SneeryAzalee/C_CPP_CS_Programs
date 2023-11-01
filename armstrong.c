#include <stdio.h>

// Make a program that will check if a number is an Armstrong number.

int main()
{
    // Introductions
    int input, main_num, check_digit, digits = 0, remainder, raw[32], result = 0;
    
    // User Input
    printf("\n\nEnter number: ");
    scanf("%d", &input);
    
    // Assignments
    check_digit = input;
    main_num = input;
    
    // Get number of digits
    while(check_digit > 0)
    {
        check_digit /= 10;
        digits++;
    }
    
    // Get the exponential result for each individual digit
    int i;
    for(i = 1; input > 0; i++)
    {
        remainder = input % 10;
        
        if(digits == 1)
        {
            raw[i] = remainder;
        }
        else if(digits > 1)
        {
            raw[i] = remainder;
            for(int j = 1; j < digits; j++)
            {
                raw[i] *= remainder;
            }
        }
        
        input /= 10;
    }
    
    // Get the visualization of the calculations
    printf("\n");
    for(int j = i - 1; j > 0; j--)
    {
        result += raw[j];
        printf("%d ", raw[j]);
        
        if(j - 1 > 0)
        {
            printf("+ ");
        }
        else
        {
            printf("= %d\n", result);
        }
    }
    
    // Evaluate if it's an Armstrong number
    if(result == main_num)
    {
        printf("\n\n%d is an Armstrong number.\n\n", main_num);
    }
    else
    {
        printf("\n\n%d is NOT an Armstrong number.\n\n", main_num);
    }
    
    return 0;
}