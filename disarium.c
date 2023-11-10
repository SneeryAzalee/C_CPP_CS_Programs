#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Make a program that will print out all the valid Disarium numbers specified by the user

int main()
{
    // Declaration
    int input_count;
    
    // Ask for number of inputs
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &input_count);
    printf("\n\nEnter inputs (Use spaces!): ");
    
    // Declare an array with the size of the number of inputs specified
    long double output[input_count];
    
    // Loop as many iterations as the number of inputs
    for(int i = 1; i <= input_count; i++)
    {
        // Declare and initialize variables
        long long input, remainder, temp, temp2 = 0L;
        long double result = 0L;
        
        // Get user's input value
        scanf("%lld", &input);
        
        // Copy input value for calculation
        temp = input;
        
        // Reverse the input value
        while(temp > 0L)
        {
            remainder = temp % 10L;
            temp2 = (temp2 * 10L) + remainder;
            temp /= 10L;
        }
        
        // Get exponential result for each input digit and add them
        for(int j = 1; temp2 > 0L; j++)
        {
            remainder = temp2 % 10L;
            result += pow(remainder, j);
            temp2 /= 10L;
        }
        
        // Save the input value if the overall result matches the input value
        if(result == input)
        {
            output[i] = input;
        }
        // If results don't match, set the value to 0 as default
        else
        {
            output[i] = 0L;
        }
    }
    
    // Print all Disarium numbers
    printf("\n\nOutput: ");
    for(int i = 1; i <= input_count; i++)
    {
        if(output[i] > 0L)
        {
            printf("%.0Lf ", output[i]);
        }
    }
    printf("\n\n");
    
    
    return 0;
}