#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Sneery
{
public:

    string mainInput;
    vector<string> inputs;
    vector<int> inputStatus;

    void setMainInput()
    {
        cout << "\nEnter inputs:\n\n>> ";
        getline(cin, mainInput);
    }

    void separateInputs()
    {
        stringstream extractor(mainInput);
        string receiver;
        while(extractor >> receiver)
        {
            inputs.push_back(receiver);
        }
    }

    bool isPerfectNumber(int input)
    {
        int sum = 0;
        for(int i = 1; i < input; i++)
        {
            if(input % i == 0)
            {
                sum += i;
            }
        }
        if(sum == input)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void validateInputs()
    {
        for(int i = 0; i < inputs.size(); i++)
        {
            bool isDigit = false;
            bool isLetter = false;
            bool invalid = false;
            for(int j = 0; j < inputs[i].length() && !invalid; j++)
            {
                if(isdigit(inputs[i][j]))
                {
                    isDigit = true;
                }
                else
                {
                    if(isValidChar(inputs[i][j]))
                    {
                        isLetter = true;
                    }
                    else
                    {
                        isDigit = true;
                        isLetter = true;
                    }
                }
                if(isDigit && isLetter)
                {
                    invalid = true;
                }
            }
            if(!invalid)
            {
                inputStatus.push_back(1);
            }
            else
            {
                inputStatus.push_back(0);
            }
        }
    }

    bool isValidChar(char input)
    {
        if(input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z')
        {
            return true;
        }
        return false;
    }

    char encrypt(char input)
    {
        // +5
        if(isdigit(input))
        {
            for(int i = 0; i < 5; i++)
            {
                if(input == '9')
                {
                    input = '0';
                    continue;
                }
                input++;
            }
        }
        else
        {
            if(input >= 'A' && input <= 'Z')
            {
                for(int i = 0; i < 5; i++)
                {
                    if(input == 'Z')
                    {
                        input = 'a';
                        continue;
                    }
                    input++;
                }
            }
            else if(input >= 'a' && input <= 'z')
            {
                for(int i = 0; i < 5; i++)
                {
                    if(input == 'z')
                    {
                        input = 'A';
                        continue;
                    }
                    input++;
                }
            }
        }
        return input;
    }

    char decrypt(char input)
    {
        // -6
        if(isdigit(input))
        {
            for(int i = 0; i < 6; i++)
            {
                if(input == '0')
                {
                    input = '9';
                    continue;
                }
                input--;
            }
        }
        else
        {
            if(input >= 'A' && input <= 'Z')
            {
                for(int i = 0; i < 6; i++)
                {
                    if(input == 'A')
                    {
                        input = 'z';
                        continue;
                    }
                    input--;
                }
            }
            else if(input >= 'a' && input <= 'z')
            {
                for(int i = 0; i < 6; i++)
                {
                    if(input == 'a')
                    {
                        input = 'Z';
                        continue;
                    }
                    input--;
                }
            }
        }
        return input;
    }

    void getOutput()
    {
        cout << "\n\nOutputs:\n\n";
        for(int i = 0; i < inputs.size(); i++)
        {
            cout << ">> " << inputs[i] << " = ";
            if(inputStatus[i] == 1)
            {
                if(isdigit(inputs[i][0]))
                {
                    stringstream extractor(inputs[i]);
                    int receiver;
                    extractor >> receiver;
                    if(isPerfectNumber(receiver))
                    {
                        for(int j = 0; j < inputs[i].length(); j++)
                        {
                            cout << encrypt(inputs[i][j]);
                        }
                    }
                    else
                    {
                        for(int j = 0; j < inputs[i].length(); j++)
                        {
                            cout << decrypt(inputs[i][j]);
                        }
                    }
                }
                else
                {
                    if(isPerfectNumber(inputs[i].length()))
                    {
                        for(int j = 0; j < inputs[i].length(); j++)
                        {
                            cout << encrypt(inputs[i][j]);
                        }
                    }
                    else
                    {
                        for(int j = 0; j < inputs[i].length(); j++)
                        {
                            cout << decrypt(inputs[i][j]);
                        }
                    }
                }
            }
            else
            {
                cout << "Error!";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main()
{
    Sneery sneery;
    sneery.setMainInput();
    sneery.separateInputs();
    sneery.validateInputs();
    sneery.getOutput();

    return 0;
}