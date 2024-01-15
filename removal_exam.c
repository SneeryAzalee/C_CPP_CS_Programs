#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Make a program that will convert a binary input into decimal

int main()
{
    // Initialize
    int input_count;
    
    // Ask how many inputs
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &input_count);
    printf("\nInput/s: ");
    
    // Loop through each input
    for(int i = 1; i <= input_count; i++)
    {
        // Initialize
        char s_input[100];
        int whole_digit_count = 0, decimal_digit_count = 0, null_count = 0, decimal_mode = 0, whole_start, decimal_start;
        double sum = 0.0;
        
        // Get input
        scanf("%s", &s_input);
        
        // Get whole and decimal digit counts and store their position
        for(int j = 0; j < strlen(s_input); j++)
        {
            // Get decimal digit count and pointer location
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
            // Get whole digit count and starting position
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
        
        // Print output template
        if(i == 1)
        {
            printf("\nOutput/s: ");
        }
        
        // Only execute if both whole and decimal numbers have a value
        if(whole_digit_count > 0 && decimal_digit_count > 0)
        {
            // Initialize dynamic array for whole and decimal digits
            int whole_digits[whole_digit_count + 1], decimal_digits[decimal_digit_count + 1], index;
            
            // Store whole individual digits
            index = whole_start;
            for(int j = 1; j <= whole_digit_count; j++)
            {
                whole_digits[j] = s_input[index++] - '0';
            }
            
            // Store decimal individual digits
            index = decimal_start;
            for(int j = 1; j <= decimal_digit_count; j++)
            {
                decimal_digits[j] = s_input[index++] - '0';
            }
            
            // Convert binary whole digits into decimal
            index = 0;
            for(int j = whole_digit_count; j >= 1; j--)
            {
                sum += whole_digits[j] * pow(2, index++);
            }
            
            // Convert binary decimal digits into decimal
            index = -1;
            for(int j = 1; j <= decimal_digit_count; j++)
            {
                sum += decimal_digits[j] * pow(2, index--);
            }
            
            // Print sum / output
            printf("%lf ", sum);
        }
    }
    
    printf("\n\n");
    
    return 0;
}