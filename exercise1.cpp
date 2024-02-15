#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string input;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    
    cout << "Input/s: ";
    getline(cin, input);
    
    stringstream stream_input(input);
    string word;
    
    cout << "Output/s: ";
    
    while(stream_input >> word)
    {
        int count = 0;
        for(int i = 0; i < 5; i++)
        {
            if(word[0] == vowels[i])
            {
                count++;
                break;
            }
        }
        
        if(count == 0)
        {
            for(int i = 1; i < word.length(); i++)
            {
                char c = word[i];
                cout << c;
            }
            cout << word[0] << "ay";
        }
        else
        {
            cout << word << "ay";
        }
        
        cout << " ";
    }
    
    return 0;
}