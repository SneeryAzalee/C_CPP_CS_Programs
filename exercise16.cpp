#include <iostream>

using namespace std;

int main()
{
    string input;
    cout << "\nInput: ";
    getline(cin, input);
    
    string searchString;
    cout << "\nSearch: ";
    getline(cin, searchString);
    
    int index = input.find(searchString);
    
    cout << "\nOutput: Substring ";
    if(index > -1)
    {
        cout << "found!\n";
    }
    else
    {
        cout << "not found!\n";
    }
    
    return 0;
}