/*
    Write a program that will convert a hexadecimal number to its decimal equivalent.
    
    Ex:
    
        Input:
        
            Enter number----------->>    FFFC12
        
        Output:
        
            Decimal equivalent----->>  16776210
*/

#include <iostream>
#include <cmath>

using namespace std;

string convertToAllCaps(string input);
int charToInt(char input);

int main()
{
    string input;
    cout << "\nEnter number:\n\n>> ";
    getline(cin, input);
    
    input = convertToAllCaps(input);
    
    int decimalEquivalent = 0, power = 0;
    for(int i = input.length() - 1; i >= 0; i--)
    {
        int remainder = charToInt(input[i]);
        decimalEquivalent += remainder * (pow(16, power++));
    }
    
    cout << "\nDecimal equivalent:\n\n>> " << decimalEquivalent << "\n\n";
    
    return 0;
}

string convertToAllCaps(string input)
{
    string newInput = "";
    for(int i = 0; i < input.length(); i++)
    {
        newInput += toupper(input[i]);
    }
    return newInput;
}

int charToInt(char input)
{
    if(input >= 'A' && input <= 'Z')
    {
        return input - 55;
    }
    else if(input >= '0' && input <= '9')
    {
        return input - 48;
    }
}