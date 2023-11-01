#include <stdio.h>

// Make a program that reverses the user's input number.

int main(){

    int input, remainder, reversed, divisor = 10;
    printf("Please enter a number: ");
    scanf("%d", &input);
    printf("Reversed: ");
    
    while(input > 0){
        remainder = input % divisor;
        input = input / divisor;
        reversed = remainder;
        printf("%d", reversed);
    }    
    
    return 0;
}