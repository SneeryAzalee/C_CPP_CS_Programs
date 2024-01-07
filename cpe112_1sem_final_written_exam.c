#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Instructions: Write C programs to solve the following problems:


// Problem 1
void swap()
{
    /*
        Write a program that will ask for n numbers. Your program
        will then swap the integer part with the fractional part
        if a non-whole number is encountered in your inputs.

        Example:

            Enter number of inputs  :  4
            Enter inputs            :  123.321  123  123.15  12
            Output                  :  321.123  123  15.123  12
    */

    // Print information
    printf("\n\nYou have selected Problem 1:");
    printf("\nThis program will swap the numbers of the whole and decimal parts of your input.");
    printf("\n\nEx.  123.321  >>  321.123\n\n");
    
    // Initialize
    int input_count;

    // Ask how many inputs
    printf("\nEnter number of inputs  :  ");
    scanf("%d", &input_count);
    printf("\nInput/s   :  ");

    // Loop through all the inputs
    for(int i = 1; i <= input_count; i++)
    {
        // Initialize
        char s_input[100];
        int whole_digit_count = 0, decimal_digit_count = 0, decimal_mode = 0, null_count = 0, whole_start, decimal_start;
        
        // Get input string
        scanf("%s", &s_input);
        
        // Get digit count of whole and decimal numbers
        for(int j = 0; j < strlen(s_input); j++)
        {
            // Count decimal number digits
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
            // Count whole number digits
            else if(decimal_mode == 0)
            {
                // If it detects period(.), get the point location and switch to decimal mode
                if(s_input[j] == '.')
                {
                    decimal_start = j + 1;
                    decimal_mode = 1;
                }
                else if(s_input[j] != '0' || whole_digit_count > 0)
                {
                    // Get string starting position
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
            printf("\nOutput/s  :  ");
        }

        // Execute if input has a whole number only
        if(decimal_digit_count == 0)
        {
            // Print whole number
            for(int j = 1; j <= whole_digit_count; j++)
            {
                printf("%c", s_input[whole_start++]);
            }

            // Print separator
            printf(" ");
        }
        // Execute if input has a decimal number
        else if(decimal_digit_count > 0)
        {
            // Swap decimal number to whole
            int allow_print = 0;
            for(int j = 1; j <= decimal_digit_count; j++)
            {
                // Only start printing if it detects a number greater than 0
                if(s_input[decimal_start] != '0' && allow_print == 0)
                {
                    allow_print = 1;
                }
                if(allow_print == 1)
                {
                    printf("%c", s_input[decimal_start]);
                }
                decimal_start++;
            }
            
            // Swap whole number to decimal
            for(int j = 1; j <= whole_digit_count; j++)
            {
                if(j == 1)
                {
                    printf(".");
                }
                printf("%c", s_input[whole_start++]);
            }

            // Print separator
            printf(" ");
        }
    }
}


// Problem 2
void sort()
{
    /*
        Write a program that will ask for n numbers. Your program
        will then sort the digits in ascending order of the
        fractional part of your input.

        Example:

            Enter number of inputs  :  4
            Enter inputs            :  123.321  123  123.15  12
            Output                  :  123.123  123  123.15  12
    */

    // Print information
    printf("\n\nYou have selected Problem 2:");
    printf("\nThis program will sort the decimal part of your input in ascending order.");
    printf("\n\nEx.  123.321  >>  123.123\n\n");
    
    // Initialize
    int input_count;

    // Ask how many inputs
    printf("\nEnter number of inputs  :  ");
    scanf("%d", &input_count);
    printf("\nInput/s   :  ");

    // Loop through all the inputs
    for(int i = 1; i <= input_count; i++)
    {
        // Initialize
        char s_input[100];
        int whole_digit_count = 0, decimal_digit_count = 0, decimal_mode = 0, null_count = 0, whole_start, decimal_start;
        
        // Get input string
        scanf("%s", &s_input);
        
        // Get digit count of whole and decimal numbers
        for(int j = 0; j < strlen(s_input); j++)
        {
            // Count decimal number digits
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
            // Count whole number digits
            else if(decimal_mode == 0)
            {
                // If it detects period(.), get the point location and switch to decimal mode
                if(s_input[j] == '.')
                {
                    decimal_start = j + 1;
                    decimal_mode = 1;
                }
                else if(s_input[j] != '0' || whole_digit_count > 0)
                {
                    // Get string starting position
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
            printf("\nOutput/s  :  ");
        }
        
        // Execute if input has a whole number only
        if(decimal_digit_count == 0)
        {
            // Print whole number
            for(int j = 1; j <= whole_digit_count; j++)
            {
                printf("%c", s_input[whole_start++]);
            }

            // Print separator
            printf(" ");
        }
        // Execute if input has a decimal number
        else if(decimal_digit_count > 0)
        {
            // Print whole number
            for(int j = 1; j <= whole_digit_count; j++)
            {
                printf("%c", s_input[whole_start++]);
            }
            printf(".");

            // Arrange decimal digits in ascending order
            for(int j = 0; j <= 9; j++)
            {
                // Initialize
                int index = decimal_start;
                
                // Go through each digit
                for(int k = 1; k <= decimal_digit_count; k++)
                {
                    // Convert input string to integer
                    int digit = s_input[index++] - '0';

                    // Print decimal number
                    if(digit == j)
                    {
                        printf("%d", j);
                    }
                }
            }

            // Print separator
            printf(" ");
        }
    }
}


// Problem 3
void delete()
{
    /*
        Write a program that will ask for n numbers. Your program
        will then delete the duplicate digit(s) found in the
        integer and fractional of your input number.

        Example:

            Enter number of inputs  :  4
            Enter inputs            :  191.976  191  123.434  0.123
            Visualization           :  1 1. 76  191  12 .4 4  0.123
            Output                  :  11.76    191  12.44    0.123
    */

    // Print information
    printf("\n\nYou have selected Problem 3:");
    printf("\nThis program will remove similar digits found in both whole and decimal numbers.");
    printf("\n\nEx.  123.424  >>  13.44\n\n");
    
    // Initialize
    int input_count;

    // Ask how many inputs
    printf("\nEnter number of inputs  :  ");
    scanf("%d", &input_count);
    printf("\nInput/s   :  ");

    // Loop through all the inputs
    for(int i = 1; i <= input_count; i++)
    {
        // Initialize
        char s_input[100];
        int whole_digit_count = 0, decimal_digit_count = 0, decimal_mode = 0, null_count = 0, whole_start, decimal_start;
        
        // Get input string
        scanf("%s", &s_input);
        
        // Get digit count of whole and decimal numbers
        for(int j = 0; j < strlen(s_input); j++)
        {
            // Count decimal number digits
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
            // Count whole number digits
            else if(decimal_mode == 0)
            {
                // If it detects period(.), get the point location and switch to decimal mode
                if(s_input[j] == '.')
                {
                    decimal_start = j + 1;
                    decimal_mode = 1;
                }
                else if(s_input[j] != '0' || whole_digit_count > 0)
                {
                    // Get string starting position
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
            printf("\nOutput/s  :  ");
        }

        // Initialize dynamic array for whole and decimal digits
        char whole_digits[whole_digit_count + 1];
        char decimal_digits[decimal_digit_count + 1];
        int index;

        // Store whole number digits
        index = whole_start;
        for(int j = 1; j <= whole_digit_count; j++)
        {
            whole_digits[j] = s_input[index++];
        }

        // Store decimal number digits
        index = decimal_start;
        for(int j = 1; j <= decimal_digit_count; j++)
        {
            decimal_digits[j] = s_input[index++];
        }

        // Mark similar digits found in both whole and decimal digits
        for(int j = 1; j <= whole_digit_count; j++)
        {
            for(int k = 1; k <= decimal_digit_count; k++)
            {
                if(whole_digits[j] == decimal_digits[k])
                {
                    whole_digits[j] = '-';
                    decimal_digits[k] = '-';
                    break;
                }
            }
        }

        // Execute if whole number has no value
        if(whole_digit_count == 0)
        {
            printf("0");
            // Print decimal digits (if any)
            for(int j = 1; j <= decimal_digit_count; j++)
            {
                if(j == 1)
                {
                    printf(".");
                }
                printf("%c", decimal_digits[j]);
            }

            // Print separator
            printf(" ");
        }
        // Execute if whole number has a value
        else if(whole_digit_count > 0)
        {
            // Print whole digits
            decimal_mode = 1;
            for(int j = 1; j <= whole_digit_count; j++)
            {
                // If all digits in whole number are marked, print 0
                if(whole_digits[j] == '-' && j == whole_digit_count && decimal_mode == 1)
                {
                    printf("0");
                }
                else if(whole_digits[j] != '-')
                {
                    printf("%c", whole_digits[j]);
                    decimal_mode = 0;
                }
            }

            // Print decimal digits (if any)
            decimal_mode = 0;
            for(int j = 1; j <= decimal_digit_count; j++)
            {
                if(decimal_digits[j] != '-')
                {
                    if(decimal_mode == 0)
                    {
                        printf(".");
                        decimal_mode = 1;
                    }
                    printf("%c", decimal_digits[j]);
                }
            }

            // Print separator
            printf(" ");
        }
    }
}


// Main Function / Problem Selector
int main()
{
    // Initialize
    int selector;

    // Ask user to select a problem
    printf("\nCPE 112 - First Semester - Final Written Exam");
    printf("\nPlease select a problem:\n");
    printf("\n1) Integer-Decimal number swapper");
    printf("\n2) Decimal number ascending arrangement");
    printf("\n3) Delete similar digits in whole and decimal numbers");
    printf("\n\n>>  ");
    scanf("%d", &selector);

    // Selector
    if(selector == 1)
    {
        swap();
    }
    else if(selector == 2)
    {
        sort();
    }
    else if(selector == 3)
    {
        delete();
    }
    else
    {
        printf("\n\nInvalid selection!");
    }
    
    printf("\n\n\n");

    return 0;
}