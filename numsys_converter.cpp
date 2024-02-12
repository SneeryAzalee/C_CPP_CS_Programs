// Make a program that will convert any number system.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char dec_char(int input) // Convert integers to characters
{
    if(input >= 0 && input <= 9)
    {
        return input + 48; // ASCII 48 = '0'
    }
    else if(input >= 10 && input <= 35)
    {
        return input + 55; // ASCII 65 = 'A'
    }
}

int char_dec(char input) // Convert characters to integers
{
    if(input >= '0' && input <= '9')
    {
        return input - 48;
    }
    else if(input >= 'A' && input <= 'Z')
    {
        return input - 55;
    }
}

void convert(int input_num_system, vector<char> input_array, int output_num_system)
{
    bool negative_mode = false, decimal_mode = false;
    int locator_point = -1, power, precision = 100;
    long double converted = 0.0L;
    
    for(int i = 0; i < input_array.size(); i++) // Check if input is negative and has decimals
    {
        char c = input_array[i];
        
        if(c == '-')
        {
            negative_mode = true;
        }
        if(c == '.')
        {
            locator_point = i;
            decimal_mode = true;
        }
    }
    
    cout << "\nOutput (" << output_num_system << ") : ";
    
    if(decimal_mode)
    {
        power = 0;
        for(int i = locator_point - 1; i >= 0; i--) // Get decimal-result for the whole part
        {
            char c = input_array[i];
            
            if(c == '-' || c == '.')
            {
                continue;
            }
            else
            {
                int num = char_dec(input_array[i]);
                converted += num * pow(input_num_system, power++);
            }
        }
        
        power = -1;
        for(int i = locator_point + 1; i < input_array.size(); i++) // Get decimal-result for the decimal part
        {
            char c = input_array[i];
            
            if(c == '-' || c == '.')
            {
                continue;
            }
            else
            {
                int num = char_dec(input_array[i]);
                converted += num * pow(input_num_system, power--);
            }
        }
        
        long long whole = converted;
        long double decimal = converted - whole;
        vector<char> whole_result, decimal_result;
        
        while(whole > 0.0L) // Get remainder and convert its result to character
        {
            int remainder = whole % output_num_system;
            whole_result.push_back(dec_char(remainder));
            whole /= output_num_system;
        }
        
        while(decimal > 0.0L) // Get integer product and convert its result to character
        {
            int product = decimal * output_num_system;
            decimal_result.push_back(dec_char(product));
            decimal *= output_num_system;
            decimal -= product;
        }
        
        if(negative_mode)
        {
            cout << "-";
        }    
        for(int i = whole_result.size() - 1; i >= 0; i--)
        {
            char c = whole_result[i];
            cout << c;
        }
        cout << ".";
        for(int i = 0; i < decimal_result.size(); i++)
        {
            char c = decimal_result[i];
            cout << c;
        }
    }
    else if(!decimal_mode)
    {
        power = 0;
        for(int i = input_array.size() - 1; i >= 0; i--)
        {
            char c = input_array[i];
            
            if(c == '-' || c == '.')
            {
                continue;
            }
            else
            {
                int num = char_dec(input_array[i]);
                converted += num * pow(input_num_system, power++);
            }
        }
        
        long long whole = converted;
        vector<char> result;
        
        while(whole > 0L)
        {
            int remainder = whole % output_num_system;
            result.push_back(dec_char(remainder));
            whole /= output_num_system;
        }
        
        if(negative_mode)
        {
            cout << "-";
        }    
        for(int i = result.size() - 1; i >= 0; i--)
        {
            char c = result[i];
            cout << c;
        }
    }
}

int main()
{
    char loop;
    do // This program is loopable if and only if user enters 'y'
    {
        loop = 'n';
        int input_num_system, output_num_system;
        string input;
        vector<char> input_array;

        cout << "\nInput number system (base) : "; // Get input number system (BINARY = 2, HEX = 16)
        cin >> input_num_system;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "\nInput (" << input_num_system << ") : "; // Get input
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        transform(input.begin(), input.end(), input.begin(), ::toupper); // Force input string to be UPPERCASED

        for(int i = 0; i < input.length(); i++) // Extract each input character into an array
        {
            input_array.push_back(input[i]);
        }
        
        cout << "\nOutput number system (base) : "; // Get output number system
        cin >> output_num_system;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        convert(input_num_system, input_array, output_num_system); // Pass in input characters and input and output number systems
        
        cout << "\n\n\nConvert another? (y/n) : "; // Program loop logic
        cin >> loop;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        loop = tolower(loop); // Force input character to be lowercased
        cout << endl;
        
    } while(loop == 'y');

    return 0;
}