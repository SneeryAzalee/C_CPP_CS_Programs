#include <stdio.h>
#include <stdlib.h>

// Make a program that will INSERT a value to an array

int main()
{
    int input_count;
    
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &input_count);
    
    int array[input_count + 1];
    
    for(int i = 0; i < input_count; i++)
    {
        printf("%d. ", i + 1);
        scanf("%d", &array[i]);
    }
    
    printf("\n\n");
    for(int i = 0; i < input_count; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n\n");
    
    
    int input, index, temp;
    
    printf("Enter a number: ");
    scanf("%d", &input);
    
    printf("\nEnter index: ");
    scanf("%d", &index);
    printf("\n\n");
    
    for(int i = index; i < input_count + 1; i++)
    {
        temp = array[i];
        array[i] = input;
        input = temp;
    }
    
    printf("\n\n");
    for(int i = 0; i < input_count + 1; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n\n");
    
    
    return 0;
}