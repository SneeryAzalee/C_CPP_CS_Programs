#include <stdio.h>

// Make a program that will ask for a letter and determine its position in the alphabet.
// A = 65 ; Z = 90 | a = 97 ; z = 122 | 0. = 48 ; 9. = 57

void main()
{
    // Introductions
    char input;
    int position;
    
    // Input Loop
    for(;;)
    {
        // User Input
        printf("\n\n<Enter any number to exit>\n");
        printf("Enter a letter: ");
        scanf("%c", &input);
    
        // Alphabet Position Identifier
        if(input >= 65 && input <= 90)
        {
            // If the input is in UPPERCASE
            position = input - 64;
        }
        else if(input >= 97 && input <= 122)
        {
            // If the input is in lowercase
            position = input - 96;
        }
        else if(input >= 48 && input <= 57)
        {
            // Exit
            break;
        }
        
        // Clear scanf input new line(\n)
        getchar();
        
        // Print Output
        printf("\n\nLetter %c is the no. %d letter in the alphabet.\n\n", input, position);
    }
}