#include <stdio.h>
// Make a program that will convert a user's army time into standard time.
int main()
{
    int tempHour = 0, Minute = 0, Hour = 0, input, invalid = 0;
    printf("\n\nWelcome to NSTP Army Time Converter!\n\n");
    printf("Please enter given time \(e.g. 2359\): ");
    scanf("%d", &input);
    
    tempHour = input;
    Minute = input;
    
    for(int i = 1; i < 3; i++)
    {
        Hour = tempHour / 10;
        tempHour = Hour;
        if(Hour >= 24 && i == 2)
        {
            invalid++;
        }
    }
    for(int j = 1; j < 3; j++)
    {
        int tempMin1, tempMin2;
        if(j == 1)
        {
            tempMin1 = Minute % 10;
            Minute /= 10;
        }
        else if(j == 2)
        {
            tempMin2 = Minute % 10;
            Minute = (tempMin2 * 10) + tempMin1;
            if(Minute >= 60)
            {
                invalid++;
            }
        }
    }
    if(Hour < 12 && Hour > 0 && invalid == 0)
    {
        if(Minute < 10)
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:0%d AM\n\n", input, Hour, Minute);
        }
        else
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:%d AM\n\n", input, Hour, Minute);
        }
    }
    else if(Hour == 12 && invalid == 0)
    {
        if(Minute < 10)
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:0%d PM\n\n", input, Hour, Minute);
        }
        else
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:%d PM\n\n", input, Hour, Minute);
        }
    }
    else if(Hour > 12 && invalid == 0)
    {
        Hour -= 12;
        if(Minute < 10)
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:0%d PM\n\n", input, Hour, Minute);
        }
        else
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:%d PM\n\n", input, Hour, Minute);
        }
    }
    else if(Hour == 0 && invalid == 0)
    {
        Hour += 12;
        if(Minute < 10)
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:0%d AM\n\n", input, Hour, Minute);
        }
        else
        {
            printf("\n\nArmy Time: %d\n\nStandard Time: %d:%d AM\n\n", input, Hour, Minute);
        }
    }
    else if(invalid > 0)
    {
        printf("\n\nYou entered an invalid number. Please check your input and try again.\n\n");
    }
    
    return 0;
}