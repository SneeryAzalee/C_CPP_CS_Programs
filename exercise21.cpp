#include <iostream>
#include <vector>

using namespace std;

class Input
{
    public:
    
        string input, output = "";  
        vector<int> numList;  
        
        void setInput()
        {
            cout << "\nInput: ";
            getline(cin, input);
        }
        
        char incrementChar(char input)
        {
            if(input >= 'A' && input <= 'Z')
            {
                for(int i = 0; i < 3; i++)
                {
                    if(input + 1 <= 'Z')
                    {
                        input++;
                    }
                    else
                    {
                        input = 'A';
                    }
                }
            }
            else if(input >= 'a' && input <= 'z')
            {
                for(int i = 0; i < 3; i++)
                {
                    if(input + 1 <= 'z')
                    {
                        input++;
                    }
                    else
                    {
                        input = 'a';
                    }
                }
            }
            
            return input;
        }
};

class Output : public Input
{
    public:
    
        void calculateOutput()
        {
            for(int i = 0; i < input.length(); i++)
            {
                output += incrementChar(input[i]);
            }
        }
        
        string randomize(string input)
        {
            for(int i = 0; i < input.length(); i++)
            {
                for(int j = 0; j < input.length(); j++)
                {
                    if(input[i] < input[j])
                    {
                        char temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                    }
                }
            }
            
            return input;
        }
        
        string randomizeRev(string input)
        {
            for(int i = 0; i < input.length(); i++)
            {
                for(int j = 0; j < input.length(); j++)
                {
                    if(input[i] > input[j])
                    {
                        char temp = input[i];
                        input[i] = input[j];
                        input[j] = temp;
                    }
                }
            }
            
            return input;
        }
        
        void getOutput()
        {
            cout << "\nOutput:\n\n" << randomize(output) << "\n" << randomizeRev(output) << "\n";
        }
};

int main()
{
    Output sneery;
    sneery.setInput();
    sneery.calculateOutput();
    sneery.getOutput();
    
    return 0;
}