#include <stdio.h>

//####################################################
#include "/storage/emulated/0/Download/CodingC/emma_watson.h"
//####################################################

int main()
{
    char input[2][200];
    
    printf("\n\nEnter your name: ");
    scanf("%[^\n]s", &input[0]);
    
    watson(input[0]);
    
    return 0;
}