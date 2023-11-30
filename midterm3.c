#include <stdlib.h>
#include <stdio.h>

/*
    Make a program that will check if the
    first and last digit of the user input
    is greater/less than themselves. If the
    first digit is less than the last digit,
    reverse both first and last digits. If
    the first digit is greater than the last
    digit, reverse the numbers inside the
    first and last digits.
    
    Ex:
        Input  >>  1234, 4563, 567, 987, 12345
        Output >>  4231, 4653, 765, 987, 52341
*/

int main()
{
    // Initialize
    int input_count;
    
    // Ask how many inputs
    printf("\n\n\e[1;33mEnter number of inputs: \e[1;35m");
    scanf("%d", &input_count);
    printf("\n\e[1;33mEnter inputs: \e[1;36m");
    
    // Loop through all the inputs
    for(int i = 1; i <= input_count; i++)
    {
        // Initialize
        long long input, temp, temp2;
        int digit_count = 0, remainder, first_digit, last_digit;
        
        // Ask for the input
        scanf("%lld", &input);
        
        // Assign
        temp = input;
        temp2 = input;
        
        // Get number of digits
        while(temp > 0L)
        {
            temp /= 10L;
            digit_count++;
        }
        
        // Initialize dynamic array
        int digits[digit_count + 1];
        
        // Evaluate first and last digits, separate and store each digit
        for(int j = digit_count; j > 0; j--)
        {
            // Get and store each digit
            remainder = temp2 % 10L;
            digits[j] = remainder;
            
            // Get last digit
            if(j == digit_count)
            {
                last_digit = remainder;
            }
            // Get first digit
            else if(j == 1)
            {
                first_digit = remainder;
            }
            
            // Reduce temp2
            temp2 /= 10L;
        }
        
        // If first_digit < last_digit, switch both digits
        if(first_digit < last_digit)
        {
            int bank;
            
            // Switch first and last digits
            bank = digits[1];
            digits[1] = digits[digit_count];
            digits[digit_count] = bank;
        }
        // If first_digit > last_digit, reverse the digits in between first and last digit
        else if(first_digit > last_digit)
        {
            long long bank = 0L;
            
            // Combine digits in between first and last digit
            for(int j = 2; j <= digit_count - 1; j++)
            {
                bank = (bank * 10L) + digits[j];
            }
            
            // Reverse the numbers in between first and last digit
            for(int j = 2; j <= digit_count - 1; j++)
            {
                remainder = bank % 10L;
                digits[j] = remainder;
                bank /= 10L;
            }
        }
        
        // Print results
        if(i == 1)
        {
            printf("\n\n");
        }
        printf("\e[1;30m>> \e[1;32m");
        for(int j = 1; j <= digit_count; j++)
        {
            printf("%d", digits[j]);
        }
        printf("\n");
    }
    
    // Reset format
    printf("\e[0m");
    
    
    return 0;
}