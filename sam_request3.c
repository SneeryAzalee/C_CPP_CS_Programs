#include <stdio.h>
#include <stdlib.h>

// Make a program that will reverse the input if it matches the specified number of digits.

long long reverse(long long input)
{
    // Declarations
    long long reversed = 0L, remainder;
    
    // Reverse the input
    while(input != 0L)
    {
        remainder = input % 10L;
        reversed = (reversed * 10L) + remainder;
        input /= 10L;
    }
    
    return reversed;
}


int digit_checker(long long input, long long digit_count, long long emotion_level, int message_toggle)
{
    // Declarations
    long long count = 0L;
    
    // Get the number of digits from input
    while(input != 0L)
    {
        input /= 10L;
        count++;
    }
    
    // Evaluate
    if(count == digit_count)
    {
        return 1;
    }
    else
    {
        if(message_toggle == 1)
        {
            // Dynamic messages
            switch(emotion_level)
            {
                case 1L:
                    printf("\nOops! Sorry but your input does not match the number of digits you specified. Please try again.\n\n");
                    return 0;
                        
                case 2L:
                    printf("\nDid you mistyped? That's fine, you can try again.\n\n");
                    return 0;
                        
                case 3L:
                    if(digit_count == 1L)
                    {
                        printf("\nAre you sure that's %lld digit? Check your input.\n\n", digit_count);
                        return 0;
                    }
                    else
                    {
                        printf("\nAre you sure that's %lld digits? Check your input.\n\n", digit_count);
                        return 0;
                    }
                       
                case 4L:
                    printf("\nOkay, Can You Count??\n\n");
                    return 0;   
                        
                case 5L:
                    printf("\nOh my god, you can't count\n\n");
                    return 0;   
                        
                case 6L:
                    printf("\nDUDE!! HOLY SHIT YOU'RE ACTUALLY DUMB AS FUCK\n\n");
                    return 0;   
                        
                case 7L:
                    printf("\n*#*#&$*@¥×&$;$*#,$*$?/£$?#?#$*&@\n\n");
                    return 0;   
                        
                case 8L:
                    printf("\nAIGHT, GET THE FUCK OUTTA HERE. LEARN TO COUNT YOUR BRAINCELLS, FUCKING RETARDED\n\n");
                    return 0;   
            }
        }
        
        return 0;
    }
}


int invalid_checker(long long stage, long long input, long long emotion_level)
{
    // Stage selector
    switch(stage)
    {
        // Input count stage
        case 1L:
        
            // If input is non-numeric
            if(input < 0L)
            {
                // Dynamic messages
                switch(emotion_level)
                {
                    case 1L:
                        printf("\n\nInvalid input! I only accept numerical values. Please try again.\n\n");
                        return 0;
                        
                    case 2L:
                        printf("\n\nI cannot calculate a character. Try again.\n\n");
                        return 0;
                        
                    case 3L:
                        printf("\n\nOkay, what the hell is that?\n\n");
                        return 0;   
                        
                    case 4L:
                        printf("\n\nDude, \"Numbers\", Do You Know Them?\n\n");
                        return 0;   
                        
                    case 5L:
                        printf("\n\nBRO, ARE YOU HIGH??\n\n");
                        return 0;   
                        
                    case 6L:
                        printf("\n\nOkay. What in the actual fuck.\n\n");
                        return 0;   
                        
                    case 7L:
                        printf("\n\nARE YOU FUCKING STUPID?? YOU PIECE OF BRAINLESS SHIT\n\n");
                        return 0;   
                        
                    case 8L:
                        printf("\n\nAIGHT, GET THE FUCK OUTTA HERE.\n\n");
                        return 0;   
                }
            }
            
            // If input is valid
            else
            {
                return 1;
            }
            
        // Digit count stage
        case 2L:
        
            // If input is non-numeric
            if(input < 0L)
            {
                // Dynamic messages
                switch(emotion_level)
                {
                    case 1L:
                        printf("\n\nInvalid input! I only accept numerical values. Please try again.\n\n");
                        return 0;
                        
                    case 2L:
                        printf("\n\nI cannot calculate a character. Try again.\n\n");
                        return 0;
                        
                    case 3L:
                        printf("\n\nOkay, what the hell is that?\n\n");
                        return 0;   
                        
                    case 4L:
                        printf("\n\nDude, \"Numbers\", Do You Know Them?\n\n");
                        return 0;   
                        
                    case 5L:
                        printf("\n\nBRO, ARE YOU HIGH??\n\n");
                        return 0;   
                        
                    case 6L:
                        printf("\n\nOkay. What in the actual fuck.\n\n");
                        return 0;   
                        
                    case 7L:
                        printf("\n\nARE YOU FUCKING STUPID?? YOU PIECE OF BRAINLESS SHIT\n\n");
                        return 0;   
                        
                    case 8L:
                        printf("\n\nAIGHT, GET THE FUCK OUTTA HERE.\n\n");
                        return 0;   
                }
            }
            
            // If input is valid
            else
            {
                return 1;
            }
            
        // Input stage
        case 3L:
        
            // If input is non-numeric
            if(input < 0L)
            {
                // Dynamic messages
                switch(emotion_level)
                {
                    case 1L:
                        printf("\nThat's an invalid value! Sorry, I can't calculate that. Please try again.\n\n");
                        return 0;
                        
                    case 2L:
                        printf("\nI think that's not a number. You must be mistaken. Try again.\n\n");
                        return 0;
                        
                    case 3L:
                        printf("\nOkay, we don't do that here. Enter a NUMBER.\n\n");
                        return 0;   
                        
                    case 4L:
                        printf("\nHahaha! You're very funny man.\n\n");
                        return 0;   
                        
                    case 5L:
                        printf("\nDude, What The Hell Is That??\n\n");
                        return 0;   
                        
                    case 6L:
                        printf("\nBRUDDA??! GET SOME HELP\n\n");
                        return 0;   
                        
                    case 7L:
                        printf("\nTHE FUCK??? ARE YOU RETARDED?? I'LL GIVE YOU A HEADS-UP, THAT IS NOT A FUCKING NUMBER IDIOT!\n\n");
                        return 0;   
                        
                    case 8L:
                        printf("\nAIGHT, GET THE FUCK OUTTA HERE. ALSO I'LL GIVE YOU SOME ADVICE, GO KILL YOURSELF.\n\n");
                        return 0;   
                }
            }
            
            // If input is valid
            else
            {
                return 1;
            }
    }
}


int main()
{
    // Declarations
    long long input_count = -1L, digit_count = -1L, stage = 1L, inputc_digit_trigger = 1L, trigger_limit = 8L;
    
    // Stage 1 : Get number of inputs
    while(stage == 1L && inputc_digit_trigger <= trigger_limit)
    {
        printf("\n\n>> Enter number of inputs: ");
        scanf("%lld", &input_count);
        while(getchar() != '\n');
        
        // If input is valid, proceed to stage 2
        if(invalid_checker(stage, input_count, inputc_digit_trigger))
        {
            stage++;
        }
        else
        {
            inputc_digit_trigger++;
        }
    }
    
    // Stage 2 : Get number of digits
    while(stage == 2L && inputc_digit_trigger <= trigger_limit)
    {
        printf("\n\n>> Enter number of digits: ");
        scanf("%lld", &digit_count);
        while(getchar() != '\n');
        
        // If input is valid, proceed to stage 3
        if(invalid_checker(stage, digit_count, inputc_digit_trigger))
        {
            stage++;
            printf("\n\n");
        }
        else
        {
            inputc_digit_trigger++;
        }
    }
    
    // Stage 3 : Get inputs
    long long inputs[input_count + 1L], inputs_trigger = 1L, digits_trigger = 1L;
    
    for(long long i = 0L; i < input_count && inputs_trigger <= trigger_limit && digits_trigger <= trigger_limit && stage == 3L; i++)
    {
        // Loop if there's an error
        while(inputs_trigger <= trigger_limit && digits_trigger <= trigger_limit)
        {
            // Declarations
            int invalid_input = 0, invalid_digit = 0, message_toggle = 0;
            
            // Assignments
            inputs[i] = -1L;
            
            // Get input
            printf(">> %lld. ", i + 1L);
            scanf("%lld", &inputs[i]);
            while(getchar() != '\n');
            
            // Check for errors
            invalid_input = invalid_checker(stage, inputs[i], inputs_trigger);
            invalid_digit = digit_checker(inputs[i], digit_count, digits_trigger, message_toggle);
            
            message_toggle = 1;
            
            // Reverse the input and print if it's valid
            if(invalid_input == 0)
            {
                inputs_trigger++;
            }
            else if(invalid_input == 1 && invalid_digit == 0)
            {
                digit_checker(inputs[i], digit_count, digits_trigger, message_toggle);
                digits_trigger++;
            }
            else if(invalid_input == 1 && invalid_digit == 1)
            {
                printf("\nReversed: %lld\n\n", reverse(inputs[i]));
                break;
            }
        }
    }
    
    printf("\n--- PROGRAM EXECUTION FINISHED ---\n\n");
    
    return 0;
}