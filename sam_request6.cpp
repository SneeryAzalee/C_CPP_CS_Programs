#include <iostream>

using namespace std;

// Make a program that will replace a string to a user-input substring.

int main()
{
    // Initialize
    string main_string, search_string, replace_string;
    
    // Ask for the main string
    cout << "Enter string:\n\n>> ";
    getline(cin, main_string);
    
    // Ask what string to replace from main string
    cout << "\nEnter string to replace:\n\n>> ";
    getline(cin, search_string);
    
    // Ask for the replacement string
    cout << "\nEnter replacement string:\n\n>> ";
    getline(cin, replace_string);
    
    // Get iteration data for replacements
    int iterations = 0;
    for(int i = 0; i < main_string.length();)
    {
        // Replace main string if it finds the lookup string
        i = main_string.find(search_string, i);
        if(i > -1)
        {
            iterations++;
            main_string.replace(i, search_string.length(), replace_string);
            i += search_string.length();
        }
        else
        {
            break;
        }
    }
    
    // Print iteration data
    if(iterations > 0)
    {
        cout << "\n\n<Found " << iterations << " instance/s!>\n\n\n";
    }
    else
    {
        cout << "\n\n<Keyword not found!>\n\n\n";
    }
    
    // Print main string
    cout << "Output:\n\n\n>> " << main_string << "\n\n\n";
    
    
    return 0;
}