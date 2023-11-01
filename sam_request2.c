#include <stdio.h>

int main()
{
    int int_count, digits, input, largest_num, remainder;
    
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &int_count);
    printf("\nEnter number of digits: ");
    scanf("%d", &digits);
    
    for(int i = int_count; i > 0; i--)
    {
        printf("\n\nEnter number: ");
        scanf("%d", &input);
        largest_num = 0;
        int check = input;
        int valid = 1;
        
        for(int k = 1; check > 0; k++)
        {
            check /= 10;
            if(k > digits)
            {
                valid = 0;
            }
        }
        
        if(valid == 1)
        {
            for(int j = 1; j <= digits; j++)
            {
                remainder = input % 10;
                if(input % 10 > largest_num)
                {
                    largest_num = remainder;
                }
                input /= 10;
            }
            printf("\nLargest Digit: %d\n", largest_num);
        }
        else
        {
            printf("\nThe number you entered is invalid!\n");
        }
    }
    
    return 0;
}