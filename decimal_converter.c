#include <stdio.h>
// Make a program that will convert a decimal to any of the 3 numeric system.
void main()
{
    int converter, input, raw_answer[32], final_answer = 0, is_Hex = 0;
    char final_hexadecimal[32];

    printf("\nHow would you like to convert your number? Into:\n\n");
    printf("1) Binary\n2) Octal\n3) Hexadecimal\n\n");
    scanf("%d", &converter);

// BINARY
    if(converter == 1)
    {
        printf("\nEnter number: ");
        scanf("%d", &input);
        int i = 0;

        while(input > 0)
        {
            raw_answer[i++] = input % 2;
            input = input / 2;
        }
        for(int j = i - 1; j >= 0; j--)
        {
            final_answer = final_answer * 10 + raw_answer[j];
        }
    }

// OCTAL
    else if(converter == 2)
    {
        printf("\nEnter number: ");
        scanf("%d", &input);
        int i = 0;

        while(input > 0)
        {
            raw_answer[i++] = input % 8;
            input = input / 8;
        }
        for(int j = i - 1; j >= 0; j--)
        {
            final_answer = final_answer * 10 + raw_answer[j];
        }
    }

// HEXADECIMAL
    else if(converter == 3)
    {
        printf("\nEnter number: ");
        scanf("%d", &input);
        int i = 0, raw_hexadecimal;
        is_Hex = 1;

        while(input > 0)
        {
            raw_hexadecimal = input % 16;
            final_hexadecimal[i++] = (raw_hexadecimal < 10) ? raw_hexadecimal + '0' : raw_hexadecimal - 10 + 'A';
            input = input / 16;
        }
        printf("\nResult: ");
        for(int j = i - 1; j >= 0; j--)
        {
            printf("%c", final_hexadecimal[j]);
        }
        printf("\n\n");
    }

    if(is_Hex != 1)
    {
        printf("\nResult: %d\n\n", final_answer);
    }
}