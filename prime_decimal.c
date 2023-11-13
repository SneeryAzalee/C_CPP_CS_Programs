#include <stdlib.h>
#include <stdio.h>

int main()
{
    int input_count;
    printf("Enter number of inputs: ");
    scanf("%d", &input_count);
    printf("Enter inputs: ");
    for(int i = 0; i < input_count; i++)
    {
        double input, decimal;
        int whole, rem, count = 0;
        
        scanf("%lf", &input);
        
        whole = (int)input;
        decimal = input - (double)whole;

        for(int j = 2; j < whole; j++)
        {
            rem = whole % j;
            if(rem == 0)
            {
                count++;
                break;
            }
        }

        if(i == 0)
        {
            printf("Outputs: ");
        }

        if(count == 0 && decimal > 0)
        {
            printf("%lf ", input);
        }
    }
    
    
    return 0;
}