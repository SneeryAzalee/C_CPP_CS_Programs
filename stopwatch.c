#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

// Make a program that will act as a stopwatch

int main()
{
    // Initialization
    int millisecond = 0, second = 0, minute = 0, delay_ms = 10, alarm, interval = 5;
    
    // Assignment
    alarm = interval;
    
    // Stopwatch
    for(;;)
    {
        if(millisecond < 100)
        {
            // If millisecond has 1 digit
            if(millisecond < 10)
            {
                // Print template (execute once)
                if(millisecond == 0 && second == 0 && minute == 0)
                {
                    printf("\e[1;1H00 : 00 : 00");
                    printf("\e[4;1HPress any character to start / pause.");
                    printf("\e[5;1HPress SPACEBAR to reset.");
                    
                    // Wait for user interaction (key press)
                    getch();
                }
                
                printf("\e[1;11H0%d", millisecond);
            }
            // If milliseconds have 2 digits
            else if(millisecond >= 10)
            {
                printf("\e[1;11H%d", millisecond);
            }
        }
        
        // If millisecond reaches 100, add 1 to second and reset millisecond
        else if(millisecond >= 100)
        {
            second++;
            millisecond = 0;
            printf("\e[1;11H0%d", millisecond);
            
            if(second < 60)
            {
                // If second has 1 digit
                if(second < 10)
                {
                    printf("\e[1;6H0%d", second);
                }
                // If seconds have 2 digits
                else if(second >= 10)
                {
                    printf("\e[1;6H%d", second);
                }
            }
            // If second reaches 60, add 1 to minute and reset second
            else if(second >= 60)
            {
                minute++;
                second = 0;
                printf("\e[1;6H0%d", second);
                
                // If minute has 1 digit
                if(minute < 10)
                {
                    printf("\e[1;1H0%d", minute);
                }
                // If minutes have 2 digits
                else if(minute >= 10)
                {
                    printf("\e[1;1H%d", minute);
                }
            }
        }
        
        // Alarm
        if(minute == alarm)
        {
            printf("\a");
            alarm += interval;
        }
        
        // Stopwatch controls and multiplier
        usleep(delay_ms * 1000);
        millisecond++;
        fflush(stdout);
        
        // Check if user presses a key
        if(kbhit())
        {
            // Clear the displayed key
            printf("\e[1;13H ");
            
            // If user presses any key except Spacebar, pause the stopwatch
            if(getch() != ' ')
            {
                // If user presses the Spacebar while paused, reset the time
                if(getch() == ' ')
                {
                    minute = 0;
                    second = 0;
                    millisecond = 0;
                }
            }
            // If user presses the Spacebar while running, stop the time and reset. (See first execution)
            else
            {
                minute = 0;
                second = 0;
                millisecond = 0;
            }
        }
    }
    
    
    return 0;
}