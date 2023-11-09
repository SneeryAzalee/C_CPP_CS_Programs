#include <stdio.h>
#include <stdlib.h>

// Make a program that will get the first and last digit of a given input

int main()
{
	// Declarations
	int input_count, input, input2, remainder, digit_count = 0;
	
	// Ask user for number of inputs
	printf("\n\nEnter number of inputs: ");
	scanf("%d", &input_count);
	printf("\n\n");
	
	// Get inputs
	for(int i = 1; i <= input_count; i++)
	{
		// Declarations
		int first_digit = 0, last_digit = 0;
		
		// Ask user for input
		printf("%d. ", i);
		scanf("%d", &input);
		
		// Assignments
		input2 = input;
		
		// Get number of digits from input
		while(input > 0)
		{
			input /= 10;
			digit_count++;
		}
		
		// Get first and last digit
		for(int j = 1; j <= digit_count; j++)
		{
			// Get remainder
			remainder = input2 % 10;
			
			// Get first and last digit (if input is < 10)
			if(j == 1)
			{
				last_digit = remainder;
				first_digit = remainder;
			}
			// Get first digit
			else if(j == digit_count)
			{
				first_digit = remainder;
			}
			
			// Reduce input
			input2 /= 10;
		}
		
		// Print first and last digit
		printf("\nFirst Digit: %d", first_digit);
		printf("\nLast Digit: %d\n\n", last_digit);
		
		// Preparation for another input
		digit_count = 0;
	}
	
	
	return 0;
}