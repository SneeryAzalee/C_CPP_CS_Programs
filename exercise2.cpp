#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string input;
    vector<string> array_input;
    
    cout << "Input/s: ";
    getline(cin, input);
    
    stringstream stream_input(input);
    string word;
    
    while(stream_input >> word)
    {
        array_input.push_back(word);
    }
    
    int size = array_input.size();
    
    for(int i = 0; i < size; i++)
    {
        string temp = array_input[i];
        
        if(temp != "-")
        {
            for(int j = 0; j < size; j++)
            {
                if(temp == array_input[j] && i != j)
                {
                    array_input[j] = "-";
                    array_input[i] = "-";
                }
            }
        }
    }
    
    cout << "Output/s: ";
    for(string s : array_input)
    {
        if(s != "-")
        {
            cout << s << " ";
        }
    }
    
    return 0;
}