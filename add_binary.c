#include <stdio.h>

// Make a program that will add two binaries.

void main()
{
    // Introductions
    int input1, input2, num1, num2, multiplier, remainder, raw1 = 0, raw2 = 0, result, result_temp, raw_result[32], final_result = 0;
    
    // User Input
    printf("\n\nEnter first binary: ");
    scanf("%d", &input1);
    printf("\n\nEnter second binary: ");
    scanf("%d", &input2);
    
    // Assignments
    num1 = input1;
    num2 = input2;
    
    // Get value of first input
    for(int i = 0; num1 != 0; i++)
    {
        // Assignments
        multiplier = 2;
        remainder = num1 % 10;
        
        // Multiplier or Exponent
        if(i == 0)
        {
            multiplier = 1;
        }
        else if(i == 1)
        {
            multiplier = 2;
        }
        else if(i > 1)
        {
            for(int j = 1; j < i; j++)
            {
                multiplier *= 2;
            }
        }
        
        // Combine Values
        raw1 = (remainder * multiplier) + raw1;
        num1 /= 10;
    }
    
    // Get value of second input
    for(int i = 0; num2 != 0; i++)
    {
        // Assignments
        multiplier = 2;
        remainder = num2 % 10;
        
        // Multiplier or Exponent
        if(i == 0)
        {
            multiplier = 1;
        }
        else if(i == 1)
        {
            multiplier = 2;
        }
        else if(i > 1)
        {
            for(int j = 1; j < i; j++)
            {
                multiplier *= 2;
            }
        }
        
        // Combine Values
        raw2 = (remainder * multiplier) + raw2;
        num2 /= 10;
    }
    
    // Assignments
    result_temp = raw1 + raw2;
    result = result_temp;
    int i = 0;

    // Convert result to binary
    while(result_temp > 0)
    {
        raw_result[i++] = result_temp % 2;
        result_temp /= 2;
    }
    
    // Reverse result
    for(int j = i - 1; j >= 0; j--)
    {
        final_result = final_result * 10 + raw_result[j];
    }
    
    // Print Output
    printf("\n\nThe sum of \(%d\) %d and \(%d\) %d is: \(%d\) %d\n\n", raw1, input1, raw2, input2, result, final_result);
}