#include <iostream>
#include <vector>

using namespace std;

class Sneery
{
    public:
    
        string input;
        bool isPalindrome;
        int inputNum = 0;
        
        void getInputs()
        {
            cout << "\nEnter number: ";
            getline(cin, input);
        }
        
        void palindrome()
        {
            isPalindrome = true;
            for(int i = 0, j = input.size() - 1; i < j && j > i; i++, j--)
            {
                if(input[i] != input[j])
                {
                    isPalindrome = false;
                    break;
                }
            }
        }
        
        void examine()
        {
            cout << "\nOutput: ";
            if(isPalindrome)
            {
                convertBinary();
            }
            else
            {
                reverse();
            }
            cout << "\n";
        }
        
        void convertBinary()
        {
            for(int i = 0; i < input.length(); i++)
            {
                inputNum = (inputNum * 10) + (input[i] - '0');
            }
            
            vector<int> binary;
            while(inputNum > 0)
            {
                int remainder = inputNum % 2;
                binary.push_back(remainder);
                inputNum /= 2;
            }
            
            for(int i = binary.size() - 1; i >= 0; i--)
            {
                cout << binary[i];
            }
        }
        
        void reverse()
        {
            for(int i = input.length() - 1; i >= 0; i--)
            {
                cout << input[i];
            }
        }
};

int main()
{
    Sneery sneery;
    sneery.getInputs();
    sneery.palindrome();
    sneery.examine();
    
    return 0;
}