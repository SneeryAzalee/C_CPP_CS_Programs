#include <stdio.h>
#include <stdlib.h>

// Make a program that will get the average of multiple numbers

int main()
{
    // Declarations
    int input_count = 0;
    double input[100], sum = 0, average;
    
    // Get number of inputs
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &input_count);
    printf("\n");
    
    // Get inputs and add them
    for(int i = 0; i < input_count; i++)
    {
        printf("%d. >> ", i + 1);
        scanf("%lf", &input[i]);
        
        sum += input[i];
    }
    
    // Get the average
    average = sum / input_count;
    
    // Print average
    printf("\n\nAverage: %lf\n\n", average);
    
    
    return 0;
}