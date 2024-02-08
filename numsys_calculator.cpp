#include <iostream>

using namespace std;

// Make a program that will do numerical system operations

int main()
{
    int toggle_loop = 1;
    
    while(toggle_loop == 1)
    {
        string main_input, result_type;
        
        cout << "Syntax: <input>v<type> <+-*/> (use spaces for multiple inputs)\n";
        cout << "Ex: 11011v2 + A15Ev16 (Binary + Hex)\n\n\n";
        cout << "Input/s:\n\n>> ";
        getline(cin, main_input);
        
        cout << "\nResult Type:\n\n>> ";
        getline(cin, result_type);
        
        transform(main_input.begin(), main_input.end(), main_input.begin(), ::toupper);
        transform(result_type.begin(), result_type.end(), result_type.begin(), ::tolower);
    
    
        cout << main_input << "\n" << result_type;
        
        
        cout << "\nEnter 1 to continue...\n\n:: ";
        cin >> toggle_loop;
        cout << "\n\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return 0;
}