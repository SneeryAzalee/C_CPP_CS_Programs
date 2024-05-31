/*
    Ok here it goes
    Enter a string, (multiple inputs so separated by spaces)
    in that word check if the length is a prime number,
    if it is a prime number you remove all vowels and leave the consonants
    but if that consonant is a lower case convert it into its upper case,
    for upper case convert it into its lower case,
    in the cases of only number in that word then use that actual number
    and if it is a prime number then sort in ascending order
    in the case of mixed inputs, still check if that word's length is prime or not,
    if it is then move all the numbers to the right side of that word when printing for output
    if it is composite remove all consonants and leave the vowels,
    apply the conversion on lower and upper case characters,
    and for only number input then sort in descending order
    and for mixed inputs put all the numbers at the left side when printing
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Sneery
{
    public:
    
        string mainInput;
        vector<string> inputs;
        
        void setMainInput()
        {
            cout << "\nEnter string/s:\n\n>> ";
            getline(cin, mainInput);
            stringstream extractor(mainInput);
            string receiver;
            while(extractor >> receiver)
            {
                inputs.push_back(receiver);
            }
        }
        
        void execute()
        {
            cout << "\n\nOutput/s:\n\n>> ";
            for(int i = 0; i < inputs.size(); i++)
            {
                int status = inputStatus(inputs[i]);
                // Special characters found / invalid
                if(status == 0)
                {
                    cout << "INVALID!";
                }
                // All letters
                else if(status == 1)
                {
                    bool prime = isPrime(inputs[i].length());
                    if(prime)
                    {
                        string output = removeVowels(inputs[i]);
                        output = inverseChar(output);
                        cout << output;
                    }
                    else
                    {
                        string output = removeConsonants(inputs[i]);
                        output = inverseChar(output);
                        cout << output;
                    }
                }
                // All numbers
                else if(status == 2)
                {
                    int number = stringToInt(inputs[i]);
                    bool prime = isPrime(number);
                    if(prime)
                    {
                        string output = sortIntoAscendingDigits(inputs[i]);
                        cout << output;
                    }
                    else
                    {
                        string output = sortIntoDescendingDigits(inputs[i]);
                        cout << output;
                    }
                }
                // Mixed letters and numbers
                else if(status == 3)
                {
                    bool prime = isPrime(inputs[i].length());
                    if(prime)
                    {
                        string output = moveNumbersToRight(inputs[i]);
                        cout << output;
                    }
                    else
                    {
                        string output = moveNumbersToLeft(inputs[i]);
                        cout << output;
                    }
                }
                cout << " ";
            }
            cout << "\n\n";
        }
        
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
        
        string removeVowels(string input)
        {
            string output = "";
            string vowels = "aeiou";
            for(int i = 0; i < input.length(); i++)
            {
                bool isNotVowel = true;
                for(int j = 0; j < vowels.length(); j++)
                {
                    char lowered = tolower(input[i]);
                    if(lowered == vowels[j])
                    {
                        isNotVowel = false;
                        break;
                    }
                }
                if(isNotVowel)
                {
                    output += input[i];
                }
            }
            return output;
        }
        
        string removeConsonants(string input)
        {
            string output = "";
            string vowels = "aeiou";
            for(int i = 0; i < input.length(); i++)
            {
                bool isVowel = false;
                for(int j = 0; j < vowels.length(); j++)
                {
                    char lowered = tolower(input[i]);
                    if(lowered == vowels[j])
                    {
                        isVowel = true;
                        break;
                    }
                }
                if(isVowel)
                {
                    output += input[i];
                }
            }
            return output;
        }
        
        string inverseChar(string input)
        {
            for(int i = 0; i < input.length(); i++)
            {
                if(input[i] >= 'A' && input[i] <= 'Z')
                {
                    input[i] = tolower(input[i]);
                }
                else if(input[i] >= 'a' && input[i] <= 'z')
                {
                    input[i] = toupper(input[i]);
                }
            }
            return input;
        }
        
        /*
            0 = special character / invalid
            1 = all letters
            2 = all numbers
            3 = mixed letters and numbers
        */
        int inputStatus(string input)
        {
            bool isCharacter = false;
            bool isNumber = false;
            bool isSpecial = false;
            for(int i = 0; i < input.length(); i++)
            {
                char lowered = tolower(input[i]);
                if(lowered >= 'a' && lowered <= 'z')
                {
                    isCharacter = true;
                }
                else if(lowered >= '0' && lowered <= '9')
                {
                    isNumber = true;
                }
                else
                {
                    isSpecial = true;
                }
            }
            if(isCharacter && !isNumber && !isSpecial)
            {
                return 1;
            }
            else if(!isCharacter && isNumber && !isSpecial)
            {
                return 2;
            }
            else if(isCharacter && isNumber && !isSpecial)
            {
                return 3;
            }
            else
            {
                return 0;
            }
        }
        
        int stringToInt(string input)
        {
            stringstream extractor(input);
            int receiver;
            extractor >> receiver;
            return receiver;
        }
        
        string sortIntoAscendingDigits(string input)
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
        
        string sortIntoDescendingDigits(string input)
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
        
        string moveNumbersToRight(string input)
        {
            vector<char> letters, numbers;
            for(int i = 0; i < input.length(); i++)
            {
                if(isalpha(input[i]))
                {
                    letters.push_back(input[i]);
                }
                else if(isdigit(input[i]))
                {
                    numbers.push_back(input[i]);
                }
                else
                {
                    letters.push_back(input[i]);
                }
            }
            string output = "";
            for(char c : letters)
            {
                output += c;
            }
            for(char c : numbers)
            {
                output += c;
            }
            return output;
        }
        
        string moveNumbersToLeft(string input)
        {
            vector<char> letters, numbers;
            for(int i = 0; i < input.length(); i++)
            {
                if(isalpha(input[i]))
                {
                    letters.push_back(input[i]);
                }
                else if(isdigit(input[i]))
                {
                    numbers.push_back(input[i]);
                }
                else
                {
                    letters.push_back(input[i]);
                }
            }
            string output = "";
            for(char c : numbers)
            {
                output += c;
            }
            for(char c : letters)
            {
                output += c;
            }
            return output;
        }
};

int main()
{
    Sneery sneery;
    sneery.setMainInput();
    sneery.execute();
    
    return 0;
}