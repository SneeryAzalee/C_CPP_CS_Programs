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
        int whole_digit_count = 0, decimal_digit_count = 0, decimal_mode = 0, null_count = 0;
        double input, whole, decimal;
        
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
                // If it detects period(.), switch to decimal mode
                if(s_input[j] == '.')
                {
                    decimal_mode = 1;
                }
                else if(s_input[j] != '0' || whole_digit_count > 0)
                {
                    whole_digit_count++;
                }
            }
        }
        
        // Convert input string into double data type
        sscanf(s_input, "%lf", &input);
        
        // Extract whole and decimal values
        whole = (int)input;
        decimal = input - (int)input;
        
        // Print output template once
        if(i == 1)
        {
            printf("\nOutput/s  :  ");
        }
        
        // Execute if input has a whole number only
        if(decimal_digit_count == 0)
        {
            printf("%.0lf ", whole);
        }
        // Execute if input has a decimal number
        else if(decimal_digit_count > 0)
        {
            // Initialize
            int digit_limiter = whole_digit_count;
            
            // Swap whole number to decimal
            while(whole_digit_count > 0)
            {
                whole /= 10;
                whole_digit_count--;
            }
            // Swap decimal number to whole
            while(decimal_digit_count > 0)
            {
                decimal *= 10;
                decimal_digit_count--;
            }
            
            // Print output
            printf("%.*lf ", digit_limiter, whole + decimal);
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
        int decimal_digit_count = 0, decimal_mode = 0, null_count = 0, point_locator;
        
        // Get input string
        scanf("%s", &s_input);
        
        // Get digit count of decimal number
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
            // Get decimal point location
            else if(decimal_mode == 0)
            {
                // If it detects period(.), switch to decimal mode
                if(s_input[j] == '.')
                {
                    point_locator = j;
                    decimal_mode = 1;
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
            printf("%d ", atoi(s_input));
        }
        // Execute if input has a decimal number
        else if(decimal_digit_count > 0)
        {
            // Print whole number
            printf("%d.", atoi(s_input));

            // Arrange decimal digits in ascending order
            for(int j = 0; j <= 9; j++)
            {
                // Initialize
                int index = point_locator + 1;
                
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
    printf("3");
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
    printf("\n3) Delete duplicate digits in whole and decimal numbers");
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