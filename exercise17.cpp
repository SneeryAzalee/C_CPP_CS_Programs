#include <iostream>
#include <sstream>

using namespace std;

bool isPrime(int input)
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
    if(input > 1 && prime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Sneery
{
    public:
    
        Sneery(string input)
        {
            mainInput = input;
        };
        
        string mainInput;
        int highestComposite = 0, lowestComposite = 0;
        bool compositesPresent = false;
        
        void getHighLowComposites()
        {
            stringstream extractor(mainInput);
            int num;
            while(extractor >> num)
            {
                if(!isPrime(num) && num > 3)
                {
                    if(lowestComposite == 0)
                    {
                        lowestComposite = num;
                        compositesPresent = true;
                    }
                    if(num > highestComposite)
                    {
                        highestComposite = num;
                    }
                    if(num < lowestComposite)
                    {
                        lowestComposite = num;
                    }
                }
            }
        }
        
        void getPrimeFactors()
        {
            if(compositesPresent)
            {
                cout << "\nOutputs:\n\n>> " << highestComposite << " (Highest) = ";
                for(int i = 2; highestComposite != 1; i++)
                {
                    while(true)
                    {
                        if(highestComposite % i == 0)
                        {
                            cout << i << " ";
                            highestComposite /= i;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                
                cout << "\n\n>> " << lowestComposite << " (Lowest) = ";
                for(int i = 2; lowestComposite != 1; i++)
                {
                    while(true)
                    {
                        if(lowestComposite % i == 0)
                        {
                            cout << i << " ";
                            lowestComposite /= i;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                cout << "\n";
            }
            else
            {
                cerr << "\nError: No composites found!\n";
            }
        }
};

int main()
{
    string mainInput;
    cout << "\nInput(s): ";
    getline(cin, mainInput);
    
    Sneery sneery(mainInput);
    sneery.getHighLowComposites();
    sneery.getPrimeFactors();
    
    return 0;
}