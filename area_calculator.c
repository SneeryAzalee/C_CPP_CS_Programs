#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Make a program that will solve for different geometrical areas.

long double converter(long double input, int value, int target)
{
    // If the input unit is lesser than the target unit
    while(value < target)
    {
        // 1. Square millimeters (mm²) - 2. Square centimeters (cm²)
        if(value == 49)
        {
            input /= 10.0L;
            value++;
        }
        // 2. Square centimeters (cm²) - 3. Square meters (m²)
        else if(value == 50)
        {
            input /= 100.0L;
            value++;
        }
        // 3. Square meters (m²) - 4. Square kilometers (km²)
        else if(value == 51)
        {
            //  input *= input;
            input /= 1000.0L;
            value++;
        }
        // 4. Square kilometers (km²) - 5. Square inches (in²)
        else if(value == 52)
        {
            input *= 39370.079L;
            value++;
        }
        // 5. Square inches (in²) - 6. Square feet (ft²)
        else if(value == 53)
        {
            input /= 12.0L;
            value++;
        }
        // 6. Square feet (ft²) - 7. Square yards (yd²)
        else if(value == 54)
        {
            input /= 3.0L;
            value++;
        }
        // 7. Square yards (yd²) - 8. Square miles (mi²)
        else if(value == 55)
        {
            input /= 1760.0L;
            value++;
        }
        // Exit
        else
        {
            break;
        }
    }

    // If the input unit is greater than the target unit
    while(value > target)
    {
        // 8. Square miles (mi²) - 7. Square yards (yd²)
        if(value == 56)
        {
            input *= 1760.0L;
            value--;
        }
        // 7. Square yards (yd²) - 6. Square feet (ft²)
        else if(value == 55)
        {
            input *= 3.0L;
            value--;
        }
        // 6. Square feet (ft²) - 5. Square inches (in²)
        else if(value == 54)
        {
            input *= 12.0L;
            value--;
        }
        // 5. Square inches (in²) - 4. Square kilometers (km²)
        else if(value == 53)
        {
            input /= 39370.079L;
            value--;
        }
        // 4. Square kilometers (km²) - 3. Square meters (m²)
        else if(value == 52)
        {
            input *= 1000.0L;
            value--;
        }
        // 3. Square meters (m²) - 2. Square centimeters (cm²)
        else if(value == 51)
        {
            input *= 100.0L;
            value--;
        }
        // 2. Square centimeters (cm²) - 1. Square millimeters (mm²)
        else if(value == 50)
        {
            input *= 10.0L;
            value--;
        }
        // Exit
        else
        {
            break;
        }
    }

    return input;
}


int main()
{
    // Declare looper for reusability
    int flag = 49;

    // Main Function
    while(flag == 49)
    {
        // Declare mode selector
        int mode = 0;

        // Clear the screen
        printf("\e[2J\e[H");

        // Mode Selector
        printf("#################################\n");
        printf("######## AREA CALCULATOR ########\n");
        printf("#################################\n");
        printf("\n0. Unit Converter");
        printf("\n1. Rectangle");
        printf("\n2. Square");
        printf("\n3. Triangle");
        printf("\n4. Circle");
        printf("\n5. Trapezoid");
        printf("\n6. Ellipse");
        printf("\n\n\(Enter any other character to exit\)\n\n");

        // Store choice upon key press
        for(;;)
        {
            if(kbhit())
            {
                mode = getch();
                break;
            }
        }

        // 0. Unit Converter
        if(mode == 48)
        {
            // Clear the screen
            printf("\e[2J\e[H");

            // Print title
            printf("#################################\n");
            printf("######## UNIT  CONVERTER ########\n");
            printf("#################################\n");

            // Declarations
            long double input = 0.0L, result;
            int input_unit = 0, result_unit = 0, valid = 1;
            char units[][5] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};

            // Get input unit
            while(input_unit >= 49 ^ input_unit <= 56)
            {
                printf("\e[4H\e[0J");
                printf("\nSelect the unit for the input:\n\n");
                printf("1. Millimeters (mm)\n");
                printf("2. Centimeters (cm)\n");
                printf("3. Meters (m)\n");
                printf("4. Kilometers (km)\n");
                printf("5. Inches (in)\n");
                printf("6. Feet (ft)\n");
                printf("7. Yards (yd)\n");
                printf("8. Miles (mi)\n\n");

                // Store choice upon key press
                for(;;)
                {
                    if(kbhit())
                    {
                        input_unit = getch();
                        break;
                    }
                }

                // If input is invalid
                if(input_unit >= 49 ^ input_unit <= 56)
                {
                    int choice = 0;

                    printf("\e[4H\e[0J");
                    printf("\nYou entered an invalid input!\n\n");
                    printf("\n1. Try again\n");
                    printf("\n(Enter any other value to return to the main menu)\n\n");

                    // Store choice upon key press
                    for(;;)
                    {
                        if(kbhit())
                        {
                            choice = getch();
                            break;
                        }
                    }

                    // Return to main menu
                    if(choice != 49)
                    {
                        valid = 0;
                        break;
                    }
                }
            }

            // Get input
            if(valid == 1)
            {
                // Check if user enters a valid number
                while(input <= 0 && valid == 1)
                {
                    printf("\e[4H\e[0J");
                    printf("\n>> Input (%s) : ", units[input_unit - 49]);
                    scanf("%Lf", &input);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(input <= 0)
                    {
                        int choice = 0;

                        printf("\e[4H\e[0J");
                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n\n");
                        
                        // Store choice upon key press
                        for(;;)
                        {
                            if(kbhit())
                            {
                                choice = getch();
                                break;
                            }
                        }

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                    }
                }
            }

            // Only ask for unit if valid is true
            if(valid == 1)
            {
                // Get result unit
                while(result_unit >= 49 ^ result_unit <= 56)
                {
                    printf("\e[4H\e[0J");
                    printf("\n>> Input (%s) : %Lf\n", units[input_unit - 49], input);
                    printf("\nSelect the unit for the result:\n\n");
                    printf("1. Millimeters (mm)\n");
                    printf("2. Centimeters (cm)\n");
                    printf("3. Meters (m)\n");
                    printf("4. Kilometers (km)\n");
                    printf("5. Inches (in)\n");
                    printf("6. Feet (ft)\n");
                    printf("7. Yards (yd)\n");
                    printf("8. Miles (mi)\n\n");

                    // Store choice upon key press
                    for(;;)
                    {
                        if(kbhit())
                        {
                            result_unit = getch();
                            break;
                        }
                    }

                    // If input is invalid
                    if(result_unit >= 49 ^ result_unit <= 56)
                    {
                        int choice = 0;

                        printf("\e[4H\e[0J");
                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n\n");
                        
                        // Store choice upon key press
                        for(;;)
                        {
                            if(kbhit())
                            {
                                choice = getch();
                                break;
                            }
                        }

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                            break;
                        }
                    }
                }
            }

            // Preview given before calculation
            if(valid == 1)
            {
                printf("\e[4H\e[0J");
                printf("\nInput: %Lf %s\n", input, units[input_unit - 49]);
            }

            // Calculate the result
            if(valid == 1)
            {
                result = converter(input, input_unit, result_unit);
            }

            // Print Result
            if(valid == 1)
            {
                printf("\nResult: %Lf %s\n", result, units[result_unit - 49]);
                printf("\n#################################\n");
            }

            // Continue?
            if(valid == 1)
            {
                printf("\n\n1. Calculate another\n");
                printf("\n\(Enter any other character to exit\)\n\n");

                // Store choice upon key press
                for(;;)
                {
                    if(kbhit())
                    {
                        flag = getch();
                        break;
                    }
                }
            }
        }
        // 1. Rectangle
        else if(mode == 49)
        {
            // Clear the screen
            printf("\e[2J\e[H");
            
            // Print title
            printf("#################################\n");
            printf("###### AREA OF A RECTANGLE ######\n");
            printf("#################################\n");

            // Declarations
            long double length = 0.0L, width = 0.0L, area;
            int length_unit = 0, width_unit = 0, area_unit = 0, unit_flag = 1, valid = 1;
            char units[][5] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
            char units_area[][5] = {"mm²", "cm²", "m²", "km²", "in²", "ft²", "yd²", "mi²"};

            // Get length unit
            printf("\e[4H\e[0J");
            printf("\nSelect the unit for the length:\n\n");
            printf("1. Millimeters (mm)\n");
            printf("2. Centimeters (cm)\n");
            printf("3. Meters (m)\n");
            printf("4. Kilometers (km)\n");
            printf("5. Inches (in)\n");
            printf("6. Feet (ft)\n");
            printf("7. Yards (yd)\n");
            printf("8. Miles (mi)\n");
            printf("\n(Enter any other value for non-units)\n\n");
            
            // Store choice upon key press
            for(;;)
            {
                if(kbhit())
                {
                    length_unit = getch();
                    break;
                }
            }

            // Check if it has a unit or a non-unit
            if(length_unit >= 49 ^ length_unit <= 56)
            {
                unit_flag = 0;
            }

            // Get length
            if(unit_flag == 1)
            {
                // Check if user enters a valid number
                while(length <= 0 && valid == 1)
                {
                    printf("\e[4H\e[0J");
                    printf("\n>> Length (%s) : ", units[length_unit - 49]);
                    scanf("%Lf", &length);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(length <= 0)
                    {
                        int choice = 0;

                        printf("\e[4H\e[0J");
                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n\n");
                        
                        // Store choice upon key press
                        for(;;)
                        {
                            if(kbhit())
                            {
                                choice = getch();
                                break;
                            }
                        }

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0)
            {
                // Check if user enters a valid number
                while(length <= 0 && valid == 1)
                {
                    printf("\e[4H\e[0J");
                    printf("\n>> Length: ");
                    scanf("%Lf", &length);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(length <= 0)
                    {
                        int choice = 0;

                        printf("\e[4H\e[0J");
                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n\n");
                        
                        // Store choice upon key press
                        for(;;)
                        {
                            if(kbhit())
                            {
                                choice = getch();
                                break;
                            }
                        }

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get width unit
                printf("\e[4H\e[0J");
                printf("\n>> Length (%s) : %Lf", units[length_unit - 49], length);
                printf("\n\nSelect the unit for the width:\n\n");
                printf("1. Millimeters (mm)\n");
                printf("2. Centimeters (cm)\n");
                printf("3. Meters (m)\n");
                printf("4. Kilometers (km)\n");
                printf("5. Inches (in)\n");
                printf("6. Feet (ft)\n");
                printf("7. Yards (yd)\n");
                printf("8. Miles (mi)\n");
                printf("\n(Enter any other value for non-units)\n\n");
                
                // Store choice upon key press
                for(;;)
                {
                    if(kbhit())
                    {
                        width_unit = getch();
                        break;
                    }
                }

                // Check if it has a unit or a non-unit
                if(width_unit >= 49 ^ width_unit <= 56)
                {
                    unit_flag = 0;
                }
            }

            // Get width
            if(unit_flag == 1 && valid == 1)
            {
                // Check if user enters a valid number
                while(width <= 0 && valid == 1)
                {
                    printf("\e[4H\e[0J");
                    printf("\n>> Length (%s) : %Lf", units[length_unit - 49], length);
                    printf("\n>> Width (%s) : ", units[width_unit - 49]);
                    scanf("%Lf", &width);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(width <= 0)
                    {
                        int choice = 0;

                        printf("\e[4H\e[0J");
                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n\n");
                        
                        // Store choice upon key press
                        for(;;)
                        {
                            if(kbhit())
                            {
                                choice = getch();
                                break;
                            }
                        }

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0 && valid == 1)
            {
                // Check if user enters a valid number
                while(width <= 0 && valid == 1)
                {
                    printf("\e[4H\e[0J");
                    printf("\n>> Length: %Lf", length);
                    printf("\n>> Width: ");
                    scanf("%Lf", &width);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(width <= 0)
                    {
                        int choice = 0;

                        printf("\e[4H\e[0J");
                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n\n");
                        
                        // Store choice upon key press
                        for(;;)
                        {
                            if(kbhit())
                            {
                                choice = getch();
                                break;
                            }
                        }

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get area unit
                printf("\n\nSelect the unit for the area:\n\n");
                printf("1. Square millimeters (mm²)\n");
                printf("2. Square centimeters (cm²)\n");
                printf("3. Square meters (m²)\n");
                printf("4. Square kilometers (km²)\n");
                printf("5. Square inches (in²)\n");
                printf("6. Square feet (ft²)\n");
                printf("7. Square yards (yd²)\n");
                printf("8. Square miles (mi²)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &area_unit);

                // Check if it has a unit or a non-unit
                if(area_unit >= 49 ^ area_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n");
                    unit_flag = 0;
                }
            }

            // Preview given before calculation
            if(unit_flag == 1 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Length: %Lf %s\n", length, units[length_unit - 49]);
                printf("Width: %Lf %s\n", width, units[width_unit - 49]);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Length: %Lf\n", length);
                printf("Width: %Lf\n", width);
            }

            // Calculate the area
            if(unit_flag == 1 && valid == 1)
            {
                area = converter(length, length_unit, area_unit) * converter(width, width_unit, area_unit);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                area = length * width;
            }

            // Print Area
            if(unit_flag == 1 && valid == 1)
            {
                printf("\nArea: %Lf %s", area, units_area[area_unit - 49]);
                printf("\n#############################\n");
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\nArea: %Lf", area);
                printf("\n#############################\n");
            }

            // Continue?
            if(valid == 1)
            {
                printf("\n\n1. Calculate another\n");
                printf("\n\(Enter any other character to exit\)\n");
                printf("\n>> Enter choice: ");

                scanf("%s", &flag);
            }
        }
        // 2. Square
        else if(mode == 50)
        {
            // Print title
            printf("\n\n");
            printf("#################################\n");
            printf("####### AREA OF  A SQUARE #######\n");
            printf("#################################\n");

            // Declarations
            long double side = 0.0L, area;
            int side_unit = 0, area_unit = 0, unit_flag = 1, valid = 1;
            char units[][5] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
            char units_area[][5] = {"mm²", "cm²", "m²", "km²", "in²", "ft²", "yd²", "mi²"};

            // Get side unit
            printf("\nSelect the unit for the side:\n\n");
            printf("1. Millimeters (mm)\n");
            printf("2. Centimeters (cm)\n");
            printf("3. Meters (m)\n");
            printf("4. Kilometers (km)\n");
            printf("5. Inches (in)\n");
            printf("6. Feet (ft)\n");
            printf("7. Yards (yd)\n");
            printf("8. Miles (mi)\n");
            printf("\n(Enter any other value for non-units)\n");
            printf("\n>> Enter choice: ");
            scanf("%s", &side_unit);

            // Check if it has a unit or a non-unit
            if(side_unit >= 49 ^ side_unit <= 56)
            {
                printf("\nYou've chosen a non-unit calculation.\n\n");
                unit_flag = 0;
            }

            // Get side
            if(unit_flag == 1)
            {
                // Check if user enters a valid number
                while(side <= 0 && valid == 1)
                {
                    printf("\n>> Side (%s) : ", units[side_unit - 49]);
                    scanf("%lf", &side);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(side <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0)
            {
                // Check if user enters a valid number
                while(side <= 0 && valid == 1)
                {
                    printf("\n>> Side: ");
                    scanf("%lf", &side);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(side <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get area unit
                printf("\n\nSelect the unit for the area:\n\n");
                printf("1. Square millimeters (mm²)\n");
                printf("2. Square centimeters (cm²)\n");
                printf("3. Square meters (m²)\n");
                printf("4. Square kilometers (km²)\n");
                printf("5. Square inches (in²)\n");
                printf("6. Square feet (ft²)\n");
                printf("7. Square yards (yd²)\n");
                printf("8. Square miles (mi²)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &area_unit);

                // Check if it has a unit or a non-unit
                if(area_unit >= 49 ^ area_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n");
                    unit_flag = 0;
                }
            }

            // Preview given before calculation
            if(unit_flag == 1 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Side: %lf %s\n", side, units[side_unit - 49]);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Side: %lf\n", side);
            }

            // Calculate the area
            if(unit_flag == 1 && valid == 1)
            {
                area = pow(converter(side, side_unit, area_unit), 2);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                area = pow(side, 2);
            }

            // Print Area
            if(unit_flag == 1 && valid == 1)
            {
                printf("\nArea: %lf %s", area, units_area[area_unit - 49]);
                printf("\n#############################\n");
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\nArea: %lf", area);
                printf("\n#############################\n");
            }

            // Continue?
            if(valid == 1)
            {
                printf("\n\n1. Calculate another\n");
                printf("\n\(Enter any other character to exit\)\n");
                printf("\n>> Enter choice: ");

                scanf("%s", &flag);
            }
        }
        // 3. Triangle
        else if(mode == 51)
        {
            // Print title
            printf("\n\n");
            printf("#################################\n");
            printf("###### AREA OF  A TRIANGLE ######\n");
            printf("#################################\n");

            // Declarations
            long double base = 0.0L, height = 0.0L, area;
            int base_unit = 0, height_unit = 0, area_unit = 0, unit_flag = 1, valid = 1;
            char units[][5] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
            char units_area[][5] = {"mm²", "cm²", "m²", "km²", "in²", "ft²", "yd²", "mi²"};

            // Get base unit
            printf("\nSelect the unit for the base:\n\n");
            printf("1. Millimeters (mm)\n");
            printf("2. Centimeters (cm)\n");
            printf("3. Meters (m)\n");
            printf("4. Kilometers (km)\n");
            printf("5. Inches (in)\n");
            printf("6. Feet (ft)\n");
            printf("7. Yards (yd)\n");
            printf("8. Miles (mi)\n");
            printf("\n(Enter any other value for non-units)\n");
            printf("\n>> Enter choice: ");
            scanf("%s", &base_unit);

            // Check if it has a unit or a non-unit
            if(base_unit >= 49 ^ base_unit <= 56)
            {
                printf("\nYou've chosen a non-unit calculation.\n\n");
                unit_flag = 0;
            }

            // Get base
            if(unit_flag == 1)
            {
                // Check if user enters a valid number
                while(base <= 0 && valid == 1)
                {
                    printf("\n>> Base (%s) : ", units[base_unit - 49]);
                    scanf("%lf", &base);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(base <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0)
            {
                // Check if user enters a valid number
                while(base <= 0 && valid == 1)
                {
                    printf("\n>> Base: ");
                    scanf("%lf", &base);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(base <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get height unit
                printf("\n\nSelect the unit for the height:\n\n");
                printf("1. Millimeters (mm)\n");
                printf("2. Centimeters (cm)\n");
                printf("3. Meters (m)\n");
                printf("4. Kilometers (km)\n");
                printf("5. Inches (in)\n");
                printf("6. Feet (ft)\n");
                printf("7. Yards (yd)\n");
                printf("8. Miles (mi)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &height_unit);

                // Check if it has a unit or a non-unit
                if(height_unit >= 49 ^ height_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n\n");
                    unit_flag = 0;
                }
            }

            // Get height
            if(unit_flag == 1 && valid == 1)
            {
                // Check if user enters a valid number
                while(height <= 0 && valid == 1)
                {
                    printf("\n>> Height (%s) : ", units[height_unit - 49]);
                    scanf("%lf", &height);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(height <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0 && valid == 1)
            {
                // Check if user enters a valid number
                while(height <= 0 && valid == 1)
                {
                    printf("\n>> Height: ");
                    scanf("%lf", &height);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(height <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get area unit
                printf("\n\nSelect the unit for the area:\n\n");
                printf("1. Square millimeters (mm²)\n");
                printf("2. Square centimeters (cm²)\n");
                printf("3. Square meters (m²)\n");
                printf("4. Square kilometers (km²)\n");
                printf("5. Square inches (in²)\n");
                printf("6. Square feet (ft²)\n");
                printf("7. Square yards (yd²)\n");
                printf("8. Square miles (mi²)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &area_unit);

                // Check if it has a unit or a non-unit
                if(area_unit >= 49 ^ area_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n");
                    unit_flag = 0;
                }
            }

            // Preview given before calculation
            if(unit_flag == 1 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Base: %lf %s\n", base, units[base_unit - 49]);
                printf("Height: %lf %s\n", height, units[height_unit - 49]);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Base: %lf\n", base);
                printf("Height: %lf\n", height);
            }

            // Calculate the area
            if(unit_flag == 1 && valid == 1)
            {
                area = (converter(base, base_unit, area_unit) * converter(height, height_unit, area_unit)) / 2;
            }
            else if(unit_flag == 0 && valid == 1)
            {
                area = (base * height) / 2;
            }

            // Print Area
            if(unit_flag == 1 && valid == 1)
            {
                printf("\nArea: %lf %s", area, units_area[area_unit - 49]);
                printf("\n#############################\n");
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\nArea: %lf", area);
                printf("\n#############################\n");
            }

            // Continue?
            if(valid == 1)
            {
                printf("\n\n1. Calculate another\n");
                printf("\n\(Enter any other character to exit\)\n");
                printf("\n>> Enter choice: ");

                scanf("%s", &flag);
            }
        }
        // 4. Circle
        else if(mode == 52)
        {
            // Print title
            printf("\n\n");
            printf("#################################\n");
            printf("####### AREA OF  A CIRCLE #######\n");
            printf("#################################\n");

            // Declarations
            long double radius = 0.0L, area;
            int radius_unit = 0, area_unit = 0, unit_flag = 1, valid = 1;
            char units[][5] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
            char units_area[][5] = {"mm²", "cm²", "m²", "km²", "in²", "ft²", "yd²", "mi²"};

            // Get radius unit
            printf("\nSelect the unit for the radius:\n\n");
            printf("1. Millimeters (mm)\n");
            printf("2. Centimeters (cm)\n");
            printf("3. Meters (m)\n");
            printf("4. Kilometers (km)\n");
            printf("5. Inches (in)\n");
            printf("6. Feet (ft)\n");
            printf("7. Yards (yd)\n");
            printf("8. Miles (mi)\n");
            printf("\n(Enter any other value for non-units)\n");
            printf("\n>> Enter choice: ");
            scanf("%s", &radius_unit);

            // Check if it has a unit or a non-unit
            if(radius_unit >= 49 ^ radius_unit <= 56)
            {
                printf("\nYou've chosen a non-unit calculation.\n\n");
                unit_flag = 0;
            }

            // Get radius
            if(unit_flag == 1)
            {
                // Check if user enters a valid number
                while(radius <= 0 && valid == 1)
                {
                    printf("\n>> Radius (%s) : ", units[radius_unit - 49]);
                    scanf("%lf", &radius);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(radius <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0)
            {
                // Check if user enters a valid number
                while(radius <= 0 && valid == 1)
                {
                    printf("\n>> Radius: ");
                    scanf("%lf", &radius);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(radius <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get area unit
                printf("\n\nSelect the unit for the area:\n\n");
                printf("1. Square millimeters (mm²)\n");
                printf("2. Square centimeters (cm²)\n");
                printf("3. Square meters (m²)\n");
                printf("4. Square kilometers (km²)\n");
                printf("5. Square inches (in²)\n");
                printf("6. Square feet (ft²)\n");
                printf("7. Square yards (yd²)\n");
                printf("8. Square miles (mi²)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &area_unit);

                // Check if it has a unit or a non-unit
                if(area_unit >= 49 ^ area_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n");
                    unit_flag = 0;
                }
            }

            // Preview given before calculation
            if(unit_flag == 1 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Radius: %lf %s\n", radius, units[radius_unit - 49]);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Radius: %lf\n", radius);
            }

            // Calculate the area
            if(unit_flag == 1 && valid == 1)
            {
                area = 3.1415926536L * pow(converter(radius, radius_unit, area_unit), 2);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                area = 3.1415926536L * pow(radius, 2);
            }

            // Print Area
            if(unit_flag == 1 && valid == 1)
            {
                printf("\nArea: %lf %s", area, units_area[area_unit - 49]);
                printf("\n#############################\n");
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\nArea: %lf", area);
                printf("\n#############################\n");
            }

            // Continue?
            if(valid == 1)
            {
                printf("\n\n1. Calculate another\n");
                printf("\n\(Enter any other character to exit\)\n");
                printf("\n>> Enter choice: ");

                scanf("%s", &flag);
            }
        }
        // 5. Trapezoid
        else if(mode == 53)
        {
            // Print title
            printf("\n\n");
            printf("#################################\n");
            printf("###### AREA OF A TRAPEZOID ######\n");
            printf("#################################\n");

            // Declarations
            long double base_a = 0.0L, base_b = 0.0L, height = 0.0L, area;
            int base_a_unit = 0, base_b_unit = 0, height_unit = 0, area_unit = 0, unit_flag = 1, valid = 1;
            char units[][5] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
            char units_area[][5] = {"mm²", "cm²", "m²", "km²", "in²", "ft²", "yd²", "mi²"};

            // Get base A unit
            printf("\nSelect the unit for the base A:\n\n");
            printf("1. Millimeters (mm)\n");
            printf("2. Centimeters (cm)\n");
            printf("3. Meters (m)\n");
            printf("4. Kilometers (km)\n");
            printf("5. Inches (in)\n");
            printf("6. Feet (ft)\n");
            printf("7. Yards (yd)\n");
            printf("8. Miles (mi)\n");
            printf("\n(Enter any other value for non-units)\n");
            printf("\n>> Enter choice: ");
            scanf("%s", &base_a_unit);

            // Check if it has a unit or a non-unit
            if(base_a_unit >= 49 ^ base_a_unit <= 56)
            {
                printf("\nYou've chosen a non-unit calculation.\n\n");
                unit_flag = 0;
            }

            // Get base A
            if(unit_flag == 1)
            {
                // Check if user enters a valid number
                while(base_a <= 0 && valid == 1)
                {
                    printf("\n>> Base A (%s) : ", units[base_a_unit - 49]);
                    scanf("%lf", &base_a);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(base_a <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0)
            {
                // Check if user enters a valid number
                while(base_a <= 0 && valid == 1)
                {
                    printf("\n>> Base A: ");
                    scanf("%lf", &base_a);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(base_a <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get base B unit
                printf("\n\nSelect the unit for the base B:\n\n");
                printf("1. Millimeters (mm)\n");
                printf("2. Centimeters (cm)\n");
                printf("3. Meters (m)\n");
                printf("4. Kilometers (km)\n");
                printf("5. Inches (in)\n");
                printf("6. Feet (ft)\n");
                printf("7. Yards (yd)\n");
                printf("8. Miles (mi)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &base_b_unit);

                // Check if it has a unit or a non-unit
                if(base_b_unit >= 49 ^ base_b_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n\n");
                    unit_flag = 0;
                }
            }

            // Get base B
            if(unit_flag == 1 && valid == 1)
            {
                // Check if user enters a valid number
                while(base_b <= 0 && valid == 1)
                {
                    printf("\n>> Base B (%s) : ", units[base_b_unit - 49]);
                    scanf("%lf", &base_b);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(base_b <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0 && valid == 1)
            {
                // Check if user enters a valid number
                while(base_b <= 0 && valid == 1)
                {
                    printf("\n>> Base B: ");
                    scanf("%lf", &base_b);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(base_b <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get height unit
                printf("\n\nSelect the unit for the height:\n\n");
                printf("1. Millimeters (mm)\n");
                printf("2. Centimeters (cm)\n");
                printf("3. Meters (m)\n");
                printf("4. Kilometers (km)\n");
                printf("5. Inches (in)\n");
                printf("6. Feet (ft)\n");
                printf("7. Yards (yd)\n");
                printf("8. Miles (mi)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &height_unit);

                // Check if it has a unit or a non-unit
                if(height_unit >= 49 ^ height_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n\n");
                    unit_flag = 0;
                }
            }

            // Get height
            if(unit_flag == 1 && valid == 1)
            {
                // Check if user enters a valid number
                while(height <= 0 && valid == 1)
                {
                    printf("\n>> Height (%s) : ", units[height_unit - 49]);
                    scanf("%lf", &height);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(height <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0 && valid == 1)
            {
                // Check if user enters a valid number
                while(height <= 0 && valid == 1)
                {
                    printf("\n>> Height: ");
                    scanf("%lf", &height);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(height <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get area unit
                printf("\n\nSelect the unit for the area:\n\n");
                printf("1. Square millimeters (mm²)\n");
                printf("2. Square centimeters (cm²)\n");
                printf("3. Square meters (m²)\n");
                printf("4. Square kilometers (km²)\n");
                printf("5. Square inches (in²)\n");
                printf("6. Square feet (ft²)\n");
                printf("7. Square yards (yd²)\n");
                printf("8. Square miles (mi²)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &area_unit);

                // Check if it has a unit or a non-unit
                if(area_unit >= 49 ^ area_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n");
                    unit_flag = 0;
                }
            }

            // Preview given before calculation
            if(unit_flag == 1 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Base A: %lf %s\n", base_a, units[base_a_unit - 49]);
                printf("Base B: %lf %s\n", base_b, units[base_b_unit - 49]);
                printf("Height: %lf %s\n", height, units[height_unit - 49]);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Base A: %lf\n", base_a);
                printf("Base B: %lf\n", base_b);
                printf("Height: %lf\n", height);
            }

            // Calculate the area
            if(unit_flag == 1 && valid == 1)
            {
                area = ((converter(base_a, base_a_unit, area_unit) + converter(base_b, base_b_unit, area_unit)) / 2) * converter(height, height_unit, area_unit);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                area = ((base_a + base_b) / 2) * height;
            }

            // Print Area
            if(unit_flag == 1 && valid == 1)
            {
                printf("\nArea: %lf %s", area, units_area[area_unit - 49]);
                printf("\n#############################\n");
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\nArea: %lf", area);
                printf("\n#############################\n");
            }

            // Continue?
            if(valid == 1)
            {
                printf("\n\n1. Calculate another\n");
                printf("\n\(Enter any other character to exit\)\n");
                printf("\n>> Enter choice: ");

                scanf("%s", &flag);
            }
        }
        // 6. Ellipse
        else if(mode == 54)
        {
            // Print title
            printf("\n\n");
            printf("#################################\n");
            printf("###### AREA OF  AN ELLIPSE ######\n");
            printf("#################################\n");

            // Declarations
            long double axis_a = 0.0L, axis_b = 0.0L, area;
            int axis_a_unit = 0, axis_b_unit = 0, area_unit = 0, unit_flag = 1, valid = 1;
            char units[][5] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
            char units_area[][5] = {"mm²", "cm²", "m²", "km²", "in²", "ft²", "yd²", "mi²"};

            // Get axis A unit
            printf("\nSelect the unit for the axis A:\n\n");
            printf("1. Millimeters (mm)\n");
            printf("2. Centimeters (cm)\n");
            printf("3. Meters (m)\n");
            printf("4. Kilometers (km)\n");
            printf("5. Inches (in)\n");
            printf("6. Feet (ft)\n");
            printf("7. Yards (yd)\n");
            printf("8. Miles (mi)\n");
            printf("\n(Enter any other value for non-units)\n");
            printf("\n>> Enter choice: ");
            scanf("%s", &axis_a_unit);

            // Check if it has a unit or a non-unit
            if(axis_a_unit >= 49 ^ axis_a_unit <= 56)
            {
                printf("\nYou've chosen a non-unit calculation.\n\n");
                unit_flag = 0;
            }

            // Get axis A
            if(unit_flag == 1)
            {
                // Check if user enters a valid number
                while(axis_a <= 0 && valid == 1)
                {
                    printf("\n>> Axis A (%s) : ", units[axis_a_unit - 49]);
                    scanf("%lf", &axis_a);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(axis_a <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0)
            {
                // Check if user enters a valid number
                while(axis_a <= 0 && valid == 1)
                {
                    printf("\n>> Axis A: ");
                    scanf("%lf", &axis_a);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(axis_a <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get axis B unit
                printf("\n\nSelect the unit for the axis B:\n\n");
                printf("1. Millimeters (mm)\n");
                printf("2. Centimeters (cm)\n");
                printf("3. Meters (m)\n");
                printf("4. Kilometers (km)\n");
                printf("5. Inches (in)\n");
                printf("6. Feet (ft)\n");
                printf("7. Yards (yd)\n");
                printf("8. Miles (mi)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &axis_b_unit);

                // Check if it has a unit or a non-unit
                if(axis_b_unit >= 49 ^ axis_b_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n\n");
                    unit_flag = 0;
                }
            }

            // Get axis B
            if(unit_flag == 1 && valid == 1)
            {
                // Check if user enters a valid number
                while(axis_b <= 0 && valid == 1)
                {
                    printf("\n>> Axis B (%s) : ", units[axis_b_unit - 49]);
                    scanf("%lf", &axis_b);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(axis_b <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }
            else if(unit_flag == 0 && valid == 1)
            {
                // Check if user enters a valid number
                while(axis_b <= 0 && valid == 1)
                {
                    printf("\n>> Axis B: ");
                    scanf("%lf", &axis_b);
                    while(getchar() != '\n');

                    // If input is invalid
                    if(axis_b <= 0)
                    {
                        int choice = 0;

                        printf("\nYou entered an invalid input!\n\n");
                        printf("\n1. Try again\n");
                        printf("\n(Enter any other value to return to the main menu)\n");
                        printf("\n>> Enter choice: ");
                        scanf("%s", &choice);

                        // Return to main menu
                        if(choice != 49)
                        {
                            valid = 0;
                        }
                        // Try again
                        else if(choice == 49)
                        {
                            valid = 1;
                        }
                    }
                }
            }

            // Only ask for unit if both unit_flag and valid are true
            if(unit_flag == 1 && valid == 1)
            {
                // Get area unit
                printf("\n\nSelect the unit for the area:\n\n");
                printf("1. Square millimeters (mm²)\n");
                printf("2. Square centimeters (cm²)\n");
                printf("3. Square meters (m²)\n");
                printf("4. Square kilometers (km²)\n");
                printf("5. Square inches (in²)\n");
                printf("6. Square feet (ft²)\n");
                printf("7. Square yards (yd²)\n");
                printf("8. Square miles (mi²)\n");
                printf("\n(Enter any other value for non-units)\n");
                printf("\n>> Enter choice: ");
                scanf("%s", &area_unit);

                // Check if it has a unit or a non-unit
                if(area_unit >= 49 ^ area_unit <= 56)
                {
                    printf("\nYou've chosen a non-unit calculation.\n");
                    unit_flag = 0;
                }
            }

            // Preview given before calculation
            if(unit_flag == 1 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Axis A: %lf %s\n", axis_a, units[axis_a_unit - 49]);
                printf("Axis B: %lf %s\n", axis_b, units[axis_b_unit - 49]);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\n\n#############################\n");
                printf("Axis A: %lf\n", axis_a);
                printf("Axis B: %lf\n", axis_b);
            }

            // Calculate the area
            if(unit_flag == 1 && valid == 1)
            {
                area = 3.1415926536L * converter(axis_a, axis_a_unit, area_unit) * converter(axis_b, axis_b_unit, area_unit);
            }
            else if(unit_flag == 0 && valid == 1)
            {
                area = 3.1415926536L * axis_a * axis_b;
            }

            // Print Area
            if(unit_flag == 1 && valid == 1)
            {
                printf("\nArea: %lf %s", area, units_area[area_unit - 49]);
                printf("\n#############################\n");
            }
            else if(unit_flag == 0 && valid == 1)
            {
                printf("\nArea: %lf", area);
                printf("\n#############################\n");
            }

            // Continue?
            if(valid == 1)
            {
                printf("\n\n1. Calculate another\n");
                printf("\n\(Enter any other character to exit\)\n");
                printf("\n>> Enter choice: ");

                scanf("%s", &flag);
            }
        }
        // Exit
        else
        {
            break;
        }
    }

    return 0;
}