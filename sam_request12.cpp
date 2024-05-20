#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Sneery
{
    public:
    
        string mainInput;
        vector<string> inputs;
        vector<int> oddChars;
        vector<char> evenChars;
        
        void setMainInput()
        {
            cout << "\nEnter input/s:\n\n>> ";
            getline(cin, mainInput);
            
            stringstream extractor(mainInput);
            string receiver;
            while(extractor >> receiver)
            {
                inputs.push_back(receiver);
            }
        }
        
        int validateChar(char input)
        {
            /*
                0 = not a letter nor a number
                1 = number
                2 = letter
            */
            input = tolower(input);
            if(input >= 'a' && input <= 'z')
            {
                return 2;
            }
            else if(input >= '0' && input <= '9')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        int alphabetIndex(char input)
        {
            input = tolower(input);
            return input - ('a' - 1);
        }
        
        int toNegative(char input)
        {
            input -= '0';
            return input * -1;
        }
        
        void sortCharsAscending()
        {
            for(int i = 0; i < evenChars.size(); i++)
            {
                for(int j = 0; j < evenChars.size(); j++)
                {
                    if(evenChars[i] < evenChars[j])
                    {
                        char temp = evenChars[i];
                        evenChars[i] = evenChars[j];
                        evenChars[j] = temp;
                    }
                }
            }
        }
        
        void iterateThroughInputs()
        {
            cout << "\n\nOutputs:\n\n>> ";
            for(int i = 0; i < inputs.size(); i++)
            {
                oddChars.clear();
                evenChars.clear();
                
                solveEvenIndices(inputs[i]);
                sortCharsAscending();
                solveOddIndices(inputs[i]);
                
                getOutput(inputs[i]);
                cout << " ";
            }
            cout << "\n\n";
        }
        
        void getOutput(string input)
        {
            int evenIndex = 0;
            int oddIndex = 0;
            for(int i = 0; i < input.length(); i++)
            {
                int status = validateChar(input[i]);
                if(status)
                {
                    // EVEN
                    if(i % 2 == 0)
                    {
                        cout << evenChars[evenIndex++];
                    }
                    // ODD
                    else if(i % 2 == 1)
                    {
                        cout << oddChars[oddIndex++];
                    }
                }
                else
                {
                    cout << input[i];
                }
            }
        }
        
        void solveEvenIndices(string input)
        {
            for(int i = 0; i < input.length(); i++)
            {
                if(i % 2 == 0)
                {
                    int status = validateChar(input[i]);
                    if(status)
                    {
                        evenChars.push_back(input[i]);
                    }
                }
            }
        }
        
        void solveOddIndices(string input)
        {
            for(int i = 0; i < input.length(); i++)
            {
                if(i % 2 == 1)
                {
                    int status = validateChar(input[i]);
                    // LETTER
                    if(status == 2)
                    {
                        oddChars.push_back(alphabetIndex(input[i]));
                    }
                    // NUMBER
                    else if(status == 1)
                    {
                        oddChars.push_back(toNegative(input[i]));
                    }
                }
            }
        }
};

int main()
{
    Sneery sneery;
    sneery.setMainInput();
    sneery.iterateThroughInputs();
    
    return 0;
}