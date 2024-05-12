#include <iostream>

using namespace std;

class Psalm
{
    public:
    
        string input;
        int inputStatus;
        
        void setInput()
        {
            cout << "Enter string: ";
            getline(cin, input);
        }
        
        void getLengthResult()
        {
            inputStatus = isPrime(input.length());
        }
        
        int isPrime(int input)
        {
            bool prime = true;
            for(int i = 2; i < input; i++)
            {
                if(input % i == 0)
                {
                    prime = false;
                    break;
                }
            }
            if(prime && input > 1)
            {
                return 0;
            }
            else if(prime && input <= 1)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        
        void getResult()
        {
            cout << "\nResult: ";
            if(inputStatus == 0)
            {
                for(int i = 0; i < input.length(); i++)
                {
                    char temp = tolower(input[i]);
                    if(temp != 'a' && temp != 'e' && temp != 'i' && temp != 'o' && temp != 'u' && temp != ' ')
                    {
                        cout << input[i];
                    }
                }
            }
            else if(inputStatus == 1)
            {
                cout << "ERROR! Input length is neither prime nor composite.";
            }
            else
            {
                for(int i = 0; i < input.length(); i++)
                {
                    char temp = tolower(input[i]);
                    if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
                    {
                        cout << input[i] << " ";
                    }
                }
            }
            cout << "\n";
        }
};

int main()
{
    Psalm psalm;
    psalm.setInput();
    psalm.getLengthResult();
    psalm.getResult();
    
    return 0;
}