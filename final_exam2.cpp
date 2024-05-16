#include <iostream>
#include <sstream>

using namespace std;

class Sneery
{
    public:
    
        string mainInput;
        
        void setInput()
        {
            cout << "Enter input: ";
            getline(cin, mainInput);
        }
        
        bool isPerfect(int input)
        {
            int sum = 0;
            for(int i = 1; i < input; i++)
            {
                if(input % i == 0)
                {
                    sum += i;
                }
            }
            return (sum == input) ? true : false;
        }
};

class Sneery2 : public Sneery
{
    public:
    
        int encryptAmount = 5;
        int decryptAmount = 6;
        
        char encrypt(char input)
        {
            for(int i = 0; i < encryptAmount; i++)
            {
                if(input == 'Z')
                {
                    input = 'a';
                    continue;
                }
                else if(input == 'z')
                {
                    input = 'A';
                    continue;
                }
                else if(input == '9')
                {
                    input = '0';
                    continue;
                }
                input++;
            }
            return input;
        }
        
        char decrypt(char input)
        {
            for(int i = 0; i < decryptAmount; i++)
            {
                if(input == 'A')
                {
                    input = 'z';
                    continue;
                }
                else if(input == 'a')
                {
                    input = 'Z';
                    continue;
                }
                else if(input == '0')
                {
                    input = '9';
                    continue;
                }
                input--;
            }
            return input;
        }
};

class Sneery3 : public Sneery2
{
    public:
    
        void getOutput()
        {
            cout << "\nOutput: ";
            if(isdigit(mainInput[0]))
            {
                stringstream extractor(mainInput);
                int receiver;
                extractor >> receiver;
                
                if(isPerfect(receiver))
                {
                    for(int i = 0; i < mainInput.length(); i++)
                    {
                        cout << encrypt(mainInput[i]);
                    }
                }
                else
                {
                    for(int i = 0; i < mainInput.length(); i++)
                    {
                        cout << decrypt(mainInput[i]);
                    }
                }
            }
            else
            {
                if(isPerfect(mainInput.length()))
                {
                    for(int i = 0; i < mainInput.length(); i++)
                    {
                        cout << encrypt(mainInput[i]);
                    }
                }
                else
                {
                    for(int i = 0; i < mainInput.length(); i++)
                    {
                        cout << decrypt(mainInput[i]);
                    }
                }
            }
            cout << "\n";
        }
};

int main()
{
    Sneery3 sneery;
    sneery.setInput();
    sneery.getOutput();
    
    return 0;
}