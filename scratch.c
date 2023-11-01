#include<stdio.h>

int main()
{
    int whole, place = 0;
    double input, decimal;
    scanf("%lf", &input);
    
    whole = (int)input;
    decimal = input - (double)whole;
    
    printf("\n\n@ INITIAL @\nWhole = %d\nDecimal = %lf\nPlace = %d\n", whole, decimal, place);
    
    for(int i = 0; decimal != 0; i++)
    {
        input *= 10;
        whole = (int)input;
        decimal = input - (double)whole;
        place++;
        printf("\n\nWhole = %d\nDecimal = %lf\nPlace = %d\n", whole, decimal, place);
    }
    
    printf("\n\n@ FINAL @\nWhole = %d\nDecimal = %lf\nPlace = %d\n", whole, decimal, place);
    
    return 0;
}