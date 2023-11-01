#include <stdio.h>

void main()
{
    int input, remainder, num, answer = 0, final_answer = 0;
    printf("\n\nEnter number: ");
    scanf("%d", &input);
    num = input;
    
    while(num > 0)
    {
        remainder = num % 8;
        answer = (answer * 10) + remainder;
        num /= 8;
    }
    
    while(answer > 0)
    {
        remainder = answer % 10;
        final_answer = (final_answer * 10) + remainder;
        answer /= 10;
    }
    printf("\n\nDecimal: %d\nOctal: %d\n\n", input, final_answer);
}