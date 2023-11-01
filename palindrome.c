#include <stdio.h>

// Make a program that will check if a number is a palindrome.

int reverse(int input)
{
    int remainder, result = 0;
    while(input > 0)
    {
        remainder = input % 10;
        result = result * 10 + remainder;
        input /= 10;
    }
    return result;
}

int main()
{
    int input;
    printf("\n\nEnter number: ");
    scanf("%d", &input);
    
    if(reverse(input) == input)
    {
        printf("\n\n%d is a palindrome.\n\n", input);
    }
    else
    {
        printf("\n\n%d is not a palindrome.\n\n", input);
    }
}