#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int keypress()
{
    int count = 0;
    for(;;)
    {
        if(kbhit())
        {
            int key = getchar();
            
            if(key == '\n')
            {
                break;
            }
            
            printf("You pressed a key!\n");
            printf("Key: %c = Number: %d\n\n", key, key);
            count++;
        }
    }
    
    return count;
}




int main()
{
    int count;
    count = keypress();
    printf("\nKeypresses: %d\n", count);
    
    return 0;
}