#include <stdio.h>
#include <stdlib.h>

int main() {

    int x = 10;
    
    // Set the text color to green
    printf("\e[38;5;%dm", x);

    // Print the text "Test"
    printf("Test\n");

    // Reset the text color
    printf("\e[0m");

    return 0;
}
