#include <iostream>

using namespace std;

int main()
{
    string input;
    cout << "\nInput: ";
    getline(cin, input);
    cout << "\nOutput: ";
    
    char repeat = '\t';
    for(int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        if(repeat == '\t')
        {
            repeat = c;
            continue;
        }
        if(c == repeat)
        {
            int start = i - 1, end = i;
            for(int j = i; j < input.length(); j++)
            {
                if(input[j] == repeat)
                {
                    end = j;
                }
                else
                {
                    break;
                }
            }
            
            for(int j = start; j <= end; j++)
            {
                input[j] = '\t';
            }
            i = end;
        }
        else
        {
            repeat = c;
        }
    }
    
    for(char c : input)
    {
        if(c != '\t')
        {
            cout << c;
        }
    }
    cout << endl;
    
    return 0;
}