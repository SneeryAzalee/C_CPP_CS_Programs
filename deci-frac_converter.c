#include <stdio.h>

// Make a program that will convert a decimal into fraction.

void main()
{
    // Introductions
    long double input, decimal, num1;
    long long whole, places = 0L, numerator, denominator = 1L;
    
    // User Input
    printf("\n\nEnter decimal value: ");
    scanf("%Lf", &input);
    
    // Separate Whole and Decimal Numbers
    num1 = input;
    whole = (long long)num1;
    decimal = num1 - (long double)whole;
    
    // Check if its a decimal
    if(decimal > (long double)0L)
    {
        // Decimal Place Identifier
        while(decimal != 0.0L)
        {
            num1 *= 10.0L;
            whole = (long long)num1;
            decimal = num1 - (long double)whole;
            places++;
        }
    
        // Fraction Converter
        numerator = whole;
        for(long long i = 0L; i < places; i++)
        {
            denominator *= 10L;
        }
        
        // Fraction Simplifier
        long long lowest, gcd;
        lowest = (numerator < denominator) ? numerator : denominator;
        
        for(long long i = 1L; i <= lowest; i++)
        {
            if(numerator % i == 0L && denominator % i == 0L)
            {
                gcd = i;
            }
        }
        numerator /= gcd;
        denominator /= gcd;
    }
    else
    {
        numerator = whole;
    }
    
    // Print Improper Fraction Output
    printf("\n\nThe fraction form of the decimal %Lf is:\n\n%lld / %lld", input, numerator, denominator);
    
    // Print Mixed Fraction Output
    long long quotient;
    quotient = numerator / denominator;
    numerator %= denominator;
    printf("    OR    \(%lld\) %lld / %lld\n\n", quotient, numerator, denominator);
}