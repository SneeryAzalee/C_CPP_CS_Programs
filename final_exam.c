#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Make a program that will swap their whole and decimal part if all their digits sum up to the same number.

int main()
{
    // Initialize
    int input_count;
    
    // Ask how many inputs
    printf("\n\nEnter number of inputs:  ");
    scanf("%d", &input_count);
    printf("\nInput/s:  ");
    
    // Loop through each input
    for(int i = 1; i <= input_count; i++)
    {
        // Initialize
        char s_input[100];
        int whole_digit_count = 0, decimal_digit_count = 0, null_count = 0, decimal_mode = 0, whole_start, decimal_start;
        
        // Get input/s
        scanf("%s", &s_input);
        
        // Get digit count for both whole and decimal numbers
        for(int j = 0; j < strlen(s_input); j++)
        {
            // Get decimal digit count
            if(decimal_mode == 1)
            {
                if(s_input[j] == '0')
                {
                    null_count++;
                }
                else
                {
                    decimal_digit_count += null_count + 1;
                    null_count = 0;
                }
            }
            else if(decimal_mode == 0)
            {
                if(s_input[j] == '.')
                {
                    decimal_start = j + 1;
                    decimal_mode = 1;
                }
                else if(s_input[j] != '0' || whole_digit_count > 0)
                {
                    if(whole_digit_count == 0)
                    {
                        whole_start = j;
                    }
                    whole_digit_count++;
                }
            }
        }
        
        // Print output template once
        if(i == 1)
        {
            printf("\nOutput/s:  ");
        }
        
        // Initialize
        int whole_digits[whole_digit_count + 1], decimal_digits[decimal_digit_count + 1], index, whole_sum = 0, decimal_sum = 0;
            
        // Store individual whole digits
        index = whole_start;
        for(int j = 1; j <= whole_digit_count; j++)
        {
            whole_digits[j] = s_input[index++] - '0';
            whole_sum += whole_digits[j];
        }
            
        // Store individual decimal digits
        index = decimal_start;
        for(int j = 1; j <= decimal_digit_count; j++)
        {
            decimal_digits[j] = s_input[index++] - '0';
            decimal_sum += decimal_digits[j];
        }
        
        // If two values dont match
        if(whole_sum != decimal_sum)
        {
            printf("%.*lf ", decimal_digit_count, atof(s_input));
        }
        else if(whole_sum == decimal_sum && whole_sum + decimal_sum != 0)
        {
            // Print decimal to whole
            for(int j = 1; j <= decimal_digit_count; j++)
            {
                printf("%d", decimal_digits[j]);
            }
            
            // Print whole to decimal
            printf(".");
            for(int j = 1; j <= whole_digit_count; j++)
            {
                printf("%d", whole_digits[j]);
            }
            printf(" ");
        }
    }
    
    printf("\n\n");
    
    return 0;
}