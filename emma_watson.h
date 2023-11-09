#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Make a program that will greet the user by printing their name in a typewritter style format.

char watson(char input[1][200])
{
    // Declarations
    char greetings[10][200] = {"\n\n>> Hello, ", "<NAME GOES HERE>", "!\n", "\n>> How can I help you today?\n\n"};
    int delay_ms = 100;
    
    // Copy the name
    strcpy(greetings[1], input[0]);
    
    // Greet the user
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; greetings[i][j] != '\0'; j++)
        {
            printf("%c", greetings[i][j]);
            fflush(stdout);
            usleep(delay_ms * 1000);
        }
    }
}