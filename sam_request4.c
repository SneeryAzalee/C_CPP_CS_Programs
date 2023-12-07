#include <stdio.h>
#include <stdlib.h>

// Make a program that will arrange all prime numbers from low to high but leave the composite numbers on their place.

int prime(long long input)
{
    // Initialize
    int flag = 0;
    
    // Check divisibility
    for(long long i = 2L; i < input; i++)
    {
        if(input % i == 0L)
        {
            flag++;
            break;
        }
    }
    
    // Evaluate
    if(flag == 0 && input > 1L)
    {
        // Is prime? Yes
        return 1;
    }
    else
    {
        // Is prime? No
        return 0;
    }
}


int main()
{
    // Initialize
    int input_count;
    
    // Ask for how many inputs
    printf("\n\nEnter number of inputs: ");
    scanf("%d", &input_count);
    
    // Initialize dynamic array for the inputs
    long long inputs[input_count + 1];
    
    // Ask for the inputs
    printf("\nEnter values (Use spaces to separate): ");
    for(int i = 1; i <= input_count; i++)
    {
        scanf("%lld", &inputs[i]);
    }
    
    // Initialize dynamic array and others
    long long prime_list[input_count + 1], highest_prime = 0L;
    
    // Loop through the inputs
    for(int i = 1; i <= input_count; i++)
    {
        // Get the prime numbers, store them and get the highest prime number
        if(prime(inputs[i]))
        {
            prime_list[i] = inputs[i];
            
            if(prime_list[i] > highest_prime)
            {
                highest_prime = prime_list[i];
            }
        }
    }
    
    // Arrange the prime numbers from lowest to highest
    long long arranged_prime[input_count + 1];
    int index = 1;
    // Loop through all the numbers until it reaches highest prime
    for(long long i = 2L; i <= highest_prime; i++)
    {
        // Check each individual input
        for(int j = 1; j <= input_count; j++)
        {
            if(i == prime_list[j])
            {
                arranged_prime[index++] = prime_list[j];
            }
        }
    }
    index = 1;
    
    // Replace all prime numbers in the input array accordingly from arranged primes and print the final result
    printf("\n\nResult: ");
    for(int i = 1; i <= input_count; i++)
    {
        if(prime(inputs[i]))
        {
            inputs[i] = arranged_prime[index++];
        }
        
        printf("%lld ", inputs[i]);
    }
    printf("\n\n");
    
    
    return 0;
}