#include <iostream>

using namespace std;

// Make a program that will count the number of words in an input string.

int main()
{
    string input;
    bool toggle = true;
    int count = 0;
    
    cout << "Enter string: ";
    getline(cin, input);
    
    for(char c : input)
    {
        if(c != ' ' && toggle)
        {
            count++;
            toggle = false;
        }
        else if(c == ' ')
        {
            toggle = true;
        }
    }
    
    cout << "Word Count: " << count;
    
    return 0;
}