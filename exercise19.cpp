#include <iostream>
#include <vector>

using namespace std;

class Input
{
    public:
    
        string mainInput;
        int charCount;
    
        void setString()
        {
            cout << "Enter string: ";
            getline(cin, mainInput);
            charCount = mainInput.length();
        }
};

class HappyUnhappy : public Input
{
    public:
    
        bool happy = false;
        
        void getHappyUnhappyResult()
        {
            vector<int> separatedNums, totalSeparatedList;
            int tempCharCount = charCount, rem;
            bool imStuckInALoop = false;
            
            while(!imStuckInALoop && !happy)
            {
                separatedNums.clear();
                while(tempCharCount > 0)
                {
                    rem = tempCharCount % 10;
                    separatedNums.push_back(rem);
                    tempCharCount /= 10;
                }
                
                int squaredSum = 0;
                for(int i = 0; i < separatedNums.size(); i++)
                {
                    squaredSum += separatedNums[i] * separatedNums[i];
                }
                
                if(squaredSum != 1)
                {
                    if(totalSeparatedList.size() == 0)
                    {
                        totalSeparatedList.push_back(squaredSum);
                        tempCharCount = squaredSum;
                    }
                    else
                    {
                        bool repetitionFound = false;
                        for(int i = 0; i < totalSeparatedList.size(); i++)
                        {
                            if(squaredSum == totalSeparatedList[i])
                            {
                                repetitionFound = true;
                                break;
                            }
                        }
                        
                        if(repetitionFound)
                        {
                            imStuckInALoop = true;
                        }
                        else
                        {
                            totalSeparatedList.push_back(squaredSum);
                            tempCharCount = squaredSum;
                        }
                    }
                }
                else
                {
                    happy = true;
                }
            }
        }
};

class ModifyOutput : public HappyUnhappy
{
    public:
    
        void isHappy()
        {
            for(int i = 0; i < mainInput.length(); i++)
            {
                for(int j = 0; j < mainInput.length(); j++)
                {
                    if(mainInput[i] == mainInput[j] && i != j && mainInput[i] != '-')
                    {
                        mainInput[i] = '\a';
                        mainInput[j] = '\a';
                    }
                }
            }
            
            cout << "\nOutput: ";
            for(char c : mainInput)
            {
                if(c != '\a')
                {
                    cout << c;
                }
            }
            cout << "\n";
        }
        
        void isUnhappy()
        {
            for(int i = 0; i < mainInput.length(); i++)
            {
                for(int j = 0; j < mainInput.length(); j++)
                {
                    if(mainInput[i] < mainInput[j])
                    {
                        char temp = mainInput[i];
                        mainInput[i] = mainInput[j];
                        mainInput[j] = temp;
                    }
                }
            }
            
            cout << "\nOutput: " << mainInput << "\n";
        }
        
        void printResult()
        {
            if(happy)
            {
                isHappy();
            }
            else
            {
                isUnhappy();
            }
        }
};

int main()
{
    ModifyOutput output;
    output.setString();
    output.getHappyUnhappyResult();
    output.printResult();
    
    return 0;
}