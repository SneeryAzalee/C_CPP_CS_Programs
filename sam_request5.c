#include <stdio.h>
#include <stdlib.h>

int prime_checker(int input)
{
    int count = 0;
    for(int i = 2; i < input; i++)
    {
        if(input % i == 0)
        {
            count++;
        }
    }
    if(count == 0 && input > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    int input_count;
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &input_count);
    printf("Enter input/s: ");
    
    double inputs[input_count + 1];
    double primes[input_count + 1];
    int prime_count = 0, index = 1;
    for(int i = 1; i <= input_count; i++)
    {
        scanf("%lf", &inputs[i]);
        double whole = (int)inputs[i], decimal = inputs[i] - (int)inputs[i];
        if(decimal > 0)
        {
            if(prime_checker(whole))
            {
                primes[index++] = inputs[i];
                prime_count++;
            }
        }
    }
    
    for(int i = 1; i <= prime_count; i++)
    {
        for(int j = 1; j <= prime_count; j++)
        {
            if(primes[i] < primes[j])
            {
                double temp = primes[i];
                primes[i] = primes[j];
                primes[j] = temp;
            }
        }
    }
    
    for(int i = 1; i <= prime_count; i++)
    {
        printf("%lf ", primes[i]);
    }
    
    printf("\n\n");
}