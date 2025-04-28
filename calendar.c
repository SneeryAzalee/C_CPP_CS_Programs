#include <stdio.h>

int main() {

    int month_input, year_input, year_original;
    int century, year, month, day_per_week_counter, week_counter, day;
    double day_of_the_week;
    char month_names[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Get input month
    printf("\nEnter month (1-12): ");
    scanf("%d", &month_input);

    // Check if input month is valid
    if (month_input < 1 || month_input > 12) {
        printf("\nERROR: Invalid month!\n");
        return 1;
    }

    // Get input year
    printf("\nEnter year: ");
    scanf("%d", &year_input);

    // Check if input year is valid
    if (year_input < 0) {
        printf("\nERROR: Invalid year!\n");
        return 2;
    }

    year_original = year_input;

    // Print month and year early to the display
    printf("\n\n\t%s %d", month_names[month_input - 1], year_input);

    // Add exceptions to January and February for Zeller's formula
    if (month_input <= 2) {
        month = month_input + 12;
        year_input--;
    }
    else {
        month = month_input;
    }

    // Sort the year input into century and decades format for Zeller's formula
    year = year_input % 100;
    century = year_input / 100;

    // Zeller's day-of-the-week formula (0 = Saturday, ... 6 = Friday)
    day_of_the_week = (1 + ((13) * (month + 1) / 5) + year + (year / 4) + (century / 4) + (5 * century)) % 7;

    // Display the days of the week as the base structure
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    // Pre-add the empty spaces when starting the day of the month
    if (day_of_the_week == 0) {
        for (int i = 1; i <= 6; i++) {
            printf("    ");
        }
    }
    else {
        for (int i = 1; i < day_of_the_week; i++) {
            printf("    ");
        }
    }

    week_counter = 1;
    day_per_week_counter = (int)day_of_the_week;
    day = 1;

    // Main loop for adding dates
    for ( ; week_counter <= 6; week_counter++) {
        // Execute if the month is not February
        if (month_input != 2) {
            // Date loop
            for ( ; day <= 30; day++) {
                // Reset the day counter
                if (day_per_week_counter == 7) {
                    day_per_week_counter = 0;
                }
                // Prints the day with 3 spaces before it and 1 space after
                printf("%3d ", day);
                day_per_week_counter++;
                // If the month is one of the 31-day months, add day 31
                if (day == 30 && (month_input == 1 || month_input == 3 || month_input == 5 || month_input == 7 || month_input == 8 || month_input == 10 || month_input == 12)) {
                    printf("%3d ", ++day);
                }
                // Go to the next week if the day of week counter is 1 meaning it's Sunday
                if (day_per_week_counter == 1) {
                    day++;
                    break;
                }
            }
        }
        // Execute if the month is February
        else {
            // Date loop (same idea as the non-February loop)
            for ( ; day <= 28; day++) {
                if (day_per_week_counter == 7) {
                    day_per_week_counter = 0;
                }

                printf("%3d ", day);
                day_per_week_counter++;

                // Check if the year of that month is a leap year, if yes; then add day 29
                if (day == 28 && ((year_original % 4 == 0 && year_original % 100 != 0) || year_original % 400 == 0)) {
                    printf("%3d ", ++day);
                }

                if (day_per_week_counter == 1) {
                    day++;
                    break;
                }
            }
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}